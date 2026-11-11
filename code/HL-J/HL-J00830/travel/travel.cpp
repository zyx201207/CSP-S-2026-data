#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2,c1,c2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    ll fl=0;
    if(c1==c2)cout<<1,fl=1;
    else cout<<0;
    string x1=s1.substr(0,2),x2=s2.substr(0,2);
    ll f=0;
    if(fl&&x1==x2)cout<<1,f=1;
    else cout<<0;
    ll g=0;
    if(fl&&f&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))cout<<1,g=1;
    else cout<<0;
    if(fl&&g&&abs(ll(s1[2]-s2[2]))==1)cout<<1;
    else cout<<0;
    return 0;
    //Trick||Treat!
}
