#include<bits/stdc++.h>
using namespace std;
string a,b;
long long n,m,ans;
char ch;
struct Node{
    long long x;
    char y;
};
deque<Node>dq;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>m>>ch;
        Node f;
        f.x=m,f.y=ch;
        dq.push_back(f);
    }
    while(1){
        Node k=dq.front(),t=dq.back();
        dq.pop_front(),dq.pop_back();
        if(k.y!=t.y){
            ans+=min(k.x,t.x);
        }
        if(k.x>t.x){
            Node f;
            f.x=k.x-t.x;
            f.y=k.y;
            dq.push_front(f);
        }
        else if(k.x<t.x){
            Node f;
            f.x=t.x-k.x;
            f.y=t.y;
            dq.push_back(f);
        }
        if(dq.size()==1||dq.size()==0) break;
    }
    cout<<ans;
    return 0;
}
