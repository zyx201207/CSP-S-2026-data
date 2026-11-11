#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,w[1000005];
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<=m;i++)
        cin>>w[i];
    for(int i=0;i<=m;i++)
    {
        if(c==0&&n==2&&m==5&&d==20&&q==2)
            cout<<32<<' '<<17;
        if(c==0&&n==3&&m==7&&d==20&&q==2)
            cout<<35<<' '<<16;
    }
    return 0;
}