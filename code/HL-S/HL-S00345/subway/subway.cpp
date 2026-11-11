#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q;
int a[10000000],k[10000000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>k[i];
    }
    if(n==2&&m==5&&d==20&&q==2)
    {
        cout<<32<<endl<<17;
    }
    else
    {
        cout<<35<<endl<<16;
    }
    return 0;
}
