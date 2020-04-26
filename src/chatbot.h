#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot {
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    //destructor
    ~ChatBot();

    //// STUDENT CODE
    ////

    //copy constructor
    ChatBot(const ChatBot &other);

    // Move constructor.
    ChatBot(ChatBot &&other);

    //Copy assignment operator
    ChatBot &operator=(const ChatBot &other);

    //Move assignment operator
    ChatBot &operator=(ChatBot &&other) noexcept;

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);

    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }

    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }

    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);

    //// STUDENT CODE
    ////

    friend void swap(ChatBot &lhs, ChatBot &rhs) noexcept {
        std::swap(lhs._image, rhs._image);
        std::swap(lhs._rootNode, rhs._rootNode);
        std::swap(lhs._chatLogic, rhs._chatLogic);
        std::swap(lhs._currentNode, rhs._currentNode);
    }

    friend void clear(ChatBot &chatBot) {
        chatBot._chatLogic = nullptr;
        if (chatBot._image != NULL) {
            chatBot._image = NULL;
        }
        chatBot._currentNode = nullptr;
        chatBot._rootNode = nullptr;
    }

    ////
    //// EOF STUDENT CODE

};

#endif /* CHATBOT_H_ */