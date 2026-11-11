#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("traval.in","r",stdin);
    freopen("traval.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=0,y=0;
    for(int i=0;i<a.size();i++)
    {
        x*=10;
        x+=a[i]-'0';
    }for(int i=0;i<c.size();i++)
    {
        y*=10;
        y+=c[i]-'0';
    }
    if(x==y)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        cout<<0;
        return 0;
    }
    int z=(int)(b[2]-d[2]);
    if(abs(z)==1)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
