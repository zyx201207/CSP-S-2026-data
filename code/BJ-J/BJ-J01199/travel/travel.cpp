#include<bits/stdc++.h>
using namespace std;
const int N=10;
string s[N],c[N];
bool f(char a,char b){
    if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')){
        return 1;
    }else if((a=='D'||a=='F')&&(b=='D'||b=='F')){
        return 1;
    }
    return 0;
}
bool f2(char a,char b){
    if((a=='A'&&b=='B')||(b=='A'&&a=='B')||(a=='B'&&b=='C')||(b=='C'&&a=='B')||(a=='D'&&b=='F')||(b=='F'&&a=='D')){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c[0]>>s[0]>>c[1]>>s[1];
    if(c[0]==c[1]){
        cout<<'1';
        if(s[0][0]==s[1][0]&&s[0][1]==s[1][1]){
            cout<<'1';
            if(f(s[0][2],s[1][2])){
                cout<<'1';
                if(f2(s[0][2],s[1][2])){
                    cout<<'1';
                }else{
                    cout<<'0';
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
