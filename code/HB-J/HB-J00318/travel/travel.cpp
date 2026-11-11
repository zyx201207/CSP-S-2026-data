#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{cout<<"0000";return 0;}
    string pai1=s1.substr(0,2),pai2=s2.substr(0,2);
    if(pai1==pai2)cout<<1;
    else{cout<<"000";return 0;}
    char wei1=s1[2],wei2=s2[2];
    if(wei1<='C'&&wei2>='D'){cout<<"00";return 00;}
    else cout<<1;
    if(abs(wei1-wei2)==1||wei1=='D'&&wei2=='F'||wei1=='F'&&wei2=='D')cout<<1;
    else cout<<0;
    return 0;
}
