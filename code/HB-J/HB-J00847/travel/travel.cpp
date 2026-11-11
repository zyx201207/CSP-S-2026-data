#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c[2],C[2],s[3],S[3];
    cin>>c[0]>>c[1]>>s[0]>>s[1]>>s[2]>>C[0]>>C[1]>>S[0]>>S[1]>>S[2];
    if(c[0]==C[0]&&c[1]==C[1]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(s[0]==S[0]&&s[1]==S[1]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if((s[2]>'C'&&S[2]>'C')||(s[2]<'D'&&S[2]<'D')){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(s[2]-S[2]==1||s[2]-S[2]==-1){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
