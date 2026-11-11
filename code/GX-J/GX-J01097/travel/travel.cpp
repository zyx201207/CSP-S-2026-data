#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[2],s1[3],c2[2],s2[3];
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1])cout<<'1';
    else cout<<'0';
    if((c1[0]==c2[0]&&c1[1]==c2[1])&&(s1[0]==s2[0]&&s1[1]==s2[1]))cout<<'1';
    else cout<<'0';
    if((c1[0]==c2[0]&&c1[1]==c2[1])&&s(1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))cout<<'1';
    else cout<<'0';
    if((c1[0]==c2[0]&&c1[1]==c2[1])&&s(1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]<='C'&&s2[2]<='C')&&(s1[2]==s[2]+1&&s2[2]==s1[2]+1))cout<<'1';
    else if((c1[0]==c2[0]&&c1[1]==c2[1])&&s(1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))cout<<'1';
    else cout<<'0';
    return 0;
}
