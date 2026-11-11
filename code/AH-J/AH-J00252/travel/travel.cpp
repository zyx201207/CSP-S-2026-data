#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool flag=1;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)cout<<1;
    else{cout<<"0000";return 0;}
    string s5=s2.substr(0,2);
    string s6=s4.substr(0,2);
    if(s5==s6)cout<<1;
    else {cout<<"000";return 0;}
    char c1=s2[2];
    char c2=s4[2];
    if(c1<='C'&&c2>='D'){cout<<"00";return 0;}
    else if(c1>='D'&&c2<='C'){cout<<"00";return 0;}
    else cout<<1;
    if(c1>c2)swap(c1,c2);
    if(c2=='F'&&c1=='D')cout<<1;
    else if(int(c2-c1)==1)cout<<1;
    else cout<<"0";
    return 0;
}
