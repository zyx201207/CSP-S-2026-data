#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1;
    int c2;
    string s1;
    string s2;
    cin>>c1>>s1>>c2>>s2;
    string s1a;
    s1a=s1[0]+s1[1];
    char s2a=s1[2];
    string s1b;
    s1b=s2[0]+s2[1];
    char s2b=s2[2];
    if(c1==c2)
        cout<<1;
    else
        cout<<0;

    if(c1==c2&&s1a==s1b)
        cout<<1;
    else
        cout<<0;

    if(c1==c2&&s1a==s1b&&(s2a>='A'&&s2a<='C'&&s2b>='A'&&s2b<='C')||(s2a>='D'&&s2a<='F'&&s2b>='D'&&s2b<='F'))
        cout<<1;
    else
        cout<<0;

    if(c1==c2&&s1a==s1b&&((s2a>='A'&&s2a<='C'&&s2b>='A'&&s2b<='C')||(s2a>='D'&&s2a<='F'&&s2b>='D'&&s2b<='F'))&&abs(int(s2a)-int(s2b))==1)
        cout<<1;
    else
        cout<<0;
    cout<<"\n";
    return 0;
}
