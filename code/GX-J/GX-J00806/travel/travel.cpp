#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char a=c1[2];
    char b=c2[2];


    if(c1==c2) cout<<"1";
    else cout<<"0";

    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
    else cout<<"0";
    }

    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(s1[0]==s2[0]&&s1[1]==s2[1]){
                if(((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))||((a=='D'||a=='F')&&(b=='D'||b=='F')))cout<<"1";
            }
        }
    }
    else cout<<"0";

    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(s1[0]==s2[0]&&s1[1]==s2[1]){
                if(((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))||((a=='D'||a=='F')&&(b=='D'||b=='F'))){
                    if(s1[2]+1==s2[2]||s2[2]+1==s1[2]) cout<<"1";
                }
            }
        }
    }
    else cout<<"0";

    return 0;
}
