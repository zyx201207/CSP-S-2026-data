#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d,x,y,n,m;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        x=1;
    }
    else if(a!=c)
    {
        x=0;
    }
    if(b/10==d/10)
    {
        y=1;
    }
    else
    {
        y=0;
    }
    if((b%10=='A'||b%10=='B'||b%10=='C')&&(c%10=='A'||c%10=='B'||c%10=='c'))
    {
        n=1;
    }
    else
    {
        n=0;
    }
    if(b%10==d%10+1)
    {
        m=1;
    }
    else
    {
        m=0;
    }

    cout<<x<<y<<n<<m;
    return 0;

}
