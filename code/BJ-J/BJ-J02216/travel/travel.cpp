#include<iostream>
#include<cstring>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<'1';
            char a=s1[2],b=s2[2];
            if((a=='D'&&b=='F')||(a=='F'&&b=='D'))cout<<"11";
            else if(a=='D'||b=='D'||a=='F'||b=='F')cout<<"00";
            else{
                cout<<'1';
                if((a=='A'&&b=='C')||(a=='C'&&b=='A'))cout<<'0';
                else cout<<'1';
            }
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
