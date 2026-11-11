#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    char a=s1[2],b=s2[2];
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
        if(a>='A'&& a<='C'){
            if(b>='A'&& b<='C'){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        if(a>='D'&& a<='F'){
            if(b>='D'&& b<='F'){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    else{
        cout<<0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
        if(a-b==1||b-a==1){
            if(a=='C'&&b=='D'){
                cout<<0;
            }
            else{
                cout<<1;
            }
        }
        else{
            if((a=='D'&&b=='F')||(a=='F'&&b=='D')){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
