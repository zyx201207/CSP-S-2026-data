#include<bits/stdc++.h>
using namespace std;
string s,s2;
int c,c2,w;
int num,num2;
char sit,sit2;
int main(){
    freopen("travel5.in","r",stdin);
    freopen("travel5.out","w",stdout);
    cin>>c>>s>>c2>>s2;
    if(c==c2)cout<<1;
        else {
            cout<<"0000";
            return 0;
        }
    num+=((s[0]-'0')*10+(s[1]-'0'));
    num2+=((s2[0]-'0')*10+(s2[1]-'0'));
    if(num==num2)cout<<1;
        else{
            cout<<"000";
        return 0;
        }
    sit=s[2];
    sit2=s2[2];
    if((sit=='A'||sit=='B'||sit=='C')&&(sit2=='A'||sit2=='B'||sit2=='C'))w=1,cout<<1;
        else if((sit=='D'||sit=='F')&&(sit2=='D'||sit2=='F'))w=2,cout<<1;
            else{
                cout<<"00";
                return 0;
            }
    if(w==1&&sit==sit2+1||sit==sit2-1)cout<<1;
        else if(w==2)cout<<1;
            else cout<<0;
    return 0;
}
