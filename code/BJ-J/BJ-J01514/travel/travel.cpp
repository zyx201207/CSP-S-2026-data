#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool is=1;
    string c,s,c1,s1;
    cin>>c>>s>>c1>>s1;
    if(c==c1){
        cout<<1;
    }else{
        cout<<0;
        is=0;
    }
    if(c==c1&&s[0]==s1[0]&&s[1]==s1[1]&&is){
        cout<<1;
    }else{
        cout<<0;
        is=0;
    }
    if(c==c1&&s[0]==s1[0]&&s[1]==s1[1]&&((s[2]<='C'&&s1[2]<='C')||(s[2]>'C'&&s1[2]>'C'))&&is){
        cout<<1;
    }else{
        cout<<0;
        is=0;
    }
    if(c==c1&&s[0]==s1[0]&&s[1]==s1[1]&&((s[2]<='C'&&s1[2]<='C')||(s[2]>'C'&&s1[2]>'C'))&&(s[2]-s1[2]==1||s[2]-s1[2]==-1)&&is){
        cout<<1;
    }else{
        cout<<0;
        is=0;
    }
    return 0;
}


