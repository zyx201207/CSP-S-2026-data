#include<bits/stdc++.h>
using namespace std;
string c;
string c1;
int a,a1;
string b,b1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>a1>>b1;
    c+=b[0];
    c+=b[1];
    c1+=b1[0];
    c1+=b1[1];
    if (a==a1)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if (c==c1)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    char x=b[2];
    char x1=b1[2];
    int f=(x=='A'||x=='B'||x=='C');
    int f1=(x1=='A'||x1=='B'||x1=='C');
    if (f1==f)
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    int s=int(x);
    int s1=int(x1);
    if (s+1==s1||s==s1+1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
