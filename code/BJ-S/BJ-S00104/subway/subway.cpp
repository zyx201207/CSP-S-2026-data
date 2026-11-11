#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,k[505],d,q,w[500005],x,y;
vector<ll>a[505];
vector<ll>t[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k[i]);
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=1;j<=k[i];j++)
        {
            ll x,y;
            scanf("%lld%lld",&x,&y);
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    while(q--)
    {
        scanf("%lld%lld",&x,&y);
        if(x==y)
        {
            puts("0");
            continue;
        }
//        bool flag=0;
//        for(int i=1;i<=n;i++)
//        {
//            bool fx=0,fy=0;
//            for(int j=1;j<=k[i];j++)
//            {
//                if(a[i][j]==x)fx=1;
//                if(a[i][j]==y)fy=1;
//            }
//            if(fx&&fy)
//            {
//                flag=1;
//                break;
//            }
//        }
        printf("%lld\n",w[x]+w[y]);
        continue;
    }
    return 0;
}
