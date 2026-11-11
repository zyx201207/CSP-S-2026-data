#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    bool f1=0,f2=0,f3=0;
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1,f1=1;
    else cout<<0;
    if((stoi(s1.substr(0,2))==stoi(s2.substr(0,2)))&&f1)cout<<1,f2=1;
    else cout<<0;
    if((s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C')&&f2)cout<<1,f3=1;
    else cout<<0;
    if(abs(s1[2]-s2[2])==1&&f3)cout<<1;
    else cout<<0;
    return 0;
}

