#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char s11,s22;
    cin>>c1>>s1>>s11>>c2>>s2>>s22;
    if(c1!=c2) return cout<<"0000",0;
    cout<<1;
    if(s1!=s2) return cout<<"000",0;
    cout<<1;
    if(!((s11>='A'&&s11<='C'&&s22>='A'&&s22<='C')||(s11>='D'&&s11<='E'&&s22>='D'&&s22<='E'))) return cout<<"00",0;
    cout<<1;
    if(abs(s11-s22)>1) return cout<<"0",0;
    cout<<1;
    return 0;
}
