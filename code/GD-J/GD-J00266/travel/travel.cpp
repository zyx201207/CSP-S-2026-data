#include<bits/stdc++.h>
using namespace std;
string s[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s[1]>>s[2]>>s[3]>>s[4];
    if(s[1]==s[3]){
        cout<<"1";
        if(s[2][0]==s[4][0]&&s[2][1]==s[4][1]){
            cout<<"1";
            char x=s[2][2],y=s[4][2];
            if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')||(x=='D'||x=='F')&&(y=='D'||y=='F')){
                cout<<"1";
                if(x=='A'&&y=='B'){
                    cout<<"1";
                }else if(x=='B'&&(y=='A'||y=='C')){
                    cout<<"1";
                }else if(x=='C'&&y=='B'){
                    cout<<"1";
                }else if(x=='D'&&y=='F'){
                    cout<<"1";
                }else if(x=='F'&&y=='D'){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}