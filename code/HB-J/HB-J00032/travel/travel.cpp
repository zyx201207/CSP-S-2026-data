#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,ans="",h1,h2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        ans+='1';
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    h1=s1.substr(0,2);
    h2=s2.substr(0,2);
    if(h1==h2)ans+='1';
    else
    {
        cout<<"1000";
        return 0;
    }
    char l1=s1[2],l2=s2[2];
    if(('A'<=l1&&l1<='C'&&'A'<=l2&&l2<='C')||('D'<=l1&&l1<='F'&&'D'<=l2&&l2<='F'))ans+='1';
    else
    {
        cout<<"1100";
        return 0;
    }
    if(l1==l2+1||l2==l1+1)
    {
        cout<<"1111";
    }
    else cout<<"1110";
    return 0;
}
