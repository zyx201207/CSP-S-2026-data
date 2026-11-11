#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k[500010],a[505][5000],t[505][5000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i = 1;i <= n;i++){
        scanf("%lld",&k[i]);
        for(int j = 1;j <= k[i];j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
        }
    }
    for(int i = 1;i <= q;i++){
        long long x,y,ans = 0;
        scanf("%lld%lld",&x,&y);
        ans = w[x] + w[y];
        for(int j = x;j < y;j++){
            ans += t[j][j] + t[j][j+1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
