#include <bits/stdc++.h>
using namespace std;
bool ok=1;
string a, b, c, d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<1;
    }
    else 
    {
        cout<<0;
        ok=0;
    }
    string q, p;
    char m, n;
    for(char f:b)
    {
        if('0'<=f&&f<='9') q+=f;
        else m=f;
    }
    for(char f:d)
    {
        if('0'<=f&&f<='9') p+=f;
        else n=f;    
    }
    if(ok&&q==p)
    {
        cout<<1;
    }
    else{
        ok=0;
        cout<<0;
    }
    if(((m=='F'&&n=='D')||(m=='D'&&n=='F'))&&ok)
    {
        cout<<1;
    }
    else if(m!='D'&&m!='F'&&n!='D'&&n!='F'&&ok)
    {
        cout<<1;
    }
    else 
    {
        ok=0;
        cout<<0;
    }
    if(ok&&abs(m-n)==1)
    {
        cout<<1;
    }
    else cout<<0;
    return 0;
}