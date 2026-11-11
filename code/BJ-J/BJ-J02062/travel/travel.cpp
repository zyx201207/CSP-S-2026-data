#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //freopen("travel.in","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    long long a1,b1,c1,d1;
    a1=b[0]-'0';
    b1=a1*10+b[1]-'0';
    c1=d[0]-'0';
    d1=c1*10+d[1]-'0';
    if(b1==d1)
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(b[2]=='A'&&d[2]=='B'||d[2]=='C')
    {
        cout<<"1";
    }
    else if(b[2]=='B'&&d[2]=='A'||d[2]=='C')
    {
        cout<<"1";
    }
    else if(b[2]=='C'&&d[2]=='B'||d[2]=='A')
    {
        cout<<"1";
    }
    else if(b[2]=='D'&&d[2]=='E')
    {
        cout<<"1";
    }
    else if(b[2]=='E'&&d[2]=='D')
    {
        cout<<"1";
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(b[2]=='A'&&d[2]=='B')
    {
        cout<<"1";
    }
    else if(b[2]=='B'&&d[2]=='A')
    {
        cout<<"1";
    }
    else if(b[2]=='B'&&d[2]=='C')
    {
        cout<<"1";
    }
    else if(b[2]=='C'&&d[2]=='B')
    {
        cout<<"1";
    }
    else if(b[2]=='D'&&d[2]=='E')
    {
        cout<<"1";
    }
    else if(b[2]=='E'&&d[2]=='D')
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
