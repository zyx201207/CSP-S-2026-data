#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(s1[1]==s2[1]&&s1[0]==s2[0]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    char a=s1[2],b=s2[2];
    if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='C'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
