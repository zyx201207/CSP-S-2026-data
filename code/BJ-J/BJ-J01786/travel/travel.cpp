#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<1;
        bool pai=false,dao=false,lin=false;
        if(s1[0]==s2[0]&&s1[1]==s2[1]) pai=true;
        if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')) dao=true;
        if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')) dao=true,lin=true;
        if(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B')) dao=true;
        if(s1[2]=='D'&&s2[2]=='F') dao=true,lin=true;
        if(s1[2]=='F'&&s2[2]=='D') dao=true,lin=true;
        if(s1[2]=='A'&&s2[2]=='B') lin=true;
        if(s1[2]=='C'&&s2[2]=='B') lin=true;
        if(pai) cout<<1;
        else{
            cout<<0;
            dao=false,lin=false;
        }
        if(dao) cout<<1;
        else{
            cout<<0;
            lin=false;
        }
        if(lin) cout<<1;
        else cout<<0;
    }
    return 0;
}