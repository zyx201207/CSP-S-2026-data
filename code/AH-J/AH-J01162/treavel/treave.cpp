#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,o1,o2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    o1[0]=s1[2];
    o2[0]=s2[2];
    if(c1==c2) cout<<1;
    else {cout<<0;cout<<0;cout<<0;cout<<0;return 0;}

    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else{cout<<0;cout<<0;cout<<0;return 0;}

    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') s1[2]='1';
    else s1[2]='0';
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') s2[2]='1';
    else s2[2]='0';
    if(s1[2]==s2[2]) cout<<1;
    else{cout<<0;cout<<0;return 0;}

    if(o1[0]=='C'&&o2[0]=='D'){cout<<0; return 0;}
    if(o1[0]=='D'&&o2[0]=='C'){cout<<0; return 0;}
    if(o1[0]-o2[0]==1||o1[0]-o2[0]==-1) cout<<1;
    else cout<<0;
}
