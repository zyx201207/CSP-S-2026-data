#include<bits/stdc++.h>
using namespace std;
int main()
{freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b && a>c && a>d)
    {
        cout<<a;
    }
    if(b>c && b>a && b>d)
    {
        cout<<b;
    }
    if(c>b && c>d && c>a)
    {
        cout<<c;
    }
    if(d>a && d>c && d>b)
    {
        cout<<d;
    }
    return 0;
}
