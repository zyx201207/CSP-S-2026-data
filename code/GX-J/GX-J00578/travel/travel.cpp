#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<"1";
    else cout<<"0";
    if(c1==c2&&s1[1]==s2[1])cout<<"1";
    else cout<<"0";
    if(c1==c2&&s1[1]==s2[1]&&((s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&& s2[2]>='A'))||((s1[2]<='E'&&s1[2]>='D')&&(s2[2]<='E'&&s2[2]>='D')))cout<<"1";
    else cout<<"0";
    if(c1==c2&&s1[1]==s2[1]&&(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)&&(s1[2]!='C'&&s2[2]!='D')&&(s2[2]!='C'&&s1[2]!='D'))cout<<"1";
    else cout<<"0";
    return 0;

}
