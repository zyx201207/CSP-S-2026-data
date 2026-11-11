#include<bits/stdc++.h>
using namespace std;
bool checkk(char a,char b){
    if(a>='A'&&a<='C'&&b>='A'&&b<='C')return 1;
    if(a>='D'&&a<='F'&&b>='D'&&b<='F')return 1;
    return 0;
}
bool chekk(char a,char b){
    if(a=='A'&&b=='B')return 1;
    if(a=='B'&&b=='C')return 1;
    if(a=='D'&&b=='F')return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<'1';
            if(checkk(s1[2],s2[2])){
                cout<<'1';
                if(chekk(s1[2],s2[2])){
                    cout<<'1';
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
