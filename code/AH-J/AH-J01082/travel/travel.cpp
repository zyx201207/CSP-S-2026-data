#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    string _s1="",_s2="";
    _s1+=s1[0],_s1+=s1[1];
    _s2+=s2[0],_s2+=s2[1];
    int t1=stoi(_s1),t2=stoi(_s2);
    if(a==b) cout<<1;
    else cout<<0;
    if(a==b&&t1==t2) cout<<1;
    else cout<<0;
    if(a==b&&t1==t2&&((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='A')||(s2[2]=='A'&&s1[2]=='C')||(s2[2]=='C'&&s1[2]=='A')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='C'&&s1[2]=='B')))
        cout<<1;
    else cout<<0;
    if(a==b&&t1==t2&&((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='A')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='C'&&s1[2]=='B')))
        cout<<1;
    else cout<<0;
    return 0;
}
