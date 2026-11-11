#include<bits/stdc++.h>
using namespace std;
int n,m;bool b1,b2,b3;
string s_1,s_2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>s_1>>m>>s_2;
    if(s_1[2]=='F')
        s_1[2]='E';
    if(s_2[2]=='F')
        s_2[2]='E';
    if(n==m){
        cout<<1;
        b1=1;
    }else cout<<0;
    if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]&&b1){
        cout<<1;
        b2=1;
    }else cout<<0;
    if(((s_1[2]<='C'&&s_2[2]<='C')||(s_1[2]>'C'&&s_2[2]>'C'))&&b2){
        cout<<1;
        b3=1;
    }else cout<<0;
    if((s_1[2]+1==s_2[2]||s_2[2]+1==s_1[2])&&b3){
        cout<<1;
    }else cout<<0;
    return 0;
}
