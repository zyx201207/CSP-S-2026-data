#include <bits/stdc++.h>
using namespace std;
int same1=0,same2=0;
char a='0',b='0',c='0',d='0';
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2)a='1';
    else
    {
        cout<<a<<b<<c<<d;
        return 0;
    }


    if(s1[0]==s2[0]&&s1[1]==s2[1])b='1';
    else
    {
        cout<<a<<b<<c<<d;
        return 0;
    }

    if(s1[2]<='C'&&s1[2]>='A')same1=1;
    if(s2[2]<='C'&&s2[2]>='A')same2=1;
    if(same1==same2)c='1';
    else
    {
        cout<<a<<b<<c<<d;
        return 0;
    }

    int addd=s1[2]-s2[2];
    addd=abs(addd);
    if(addd==1)d='1';
    else if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F')d='1';
    cout<<a<<b<<c<<d;
    return 0;
}
