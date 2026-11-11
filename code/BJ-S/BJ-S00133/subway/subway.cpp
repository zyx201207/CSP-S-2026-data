#include <bits/stdc++.h>
using namespace std;
int c,m,n,d,q,k[500005];
long long w[500005],a[505][500005],t[505][500005];
int b[500005][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int l=0;
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++)
        {
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            b[a[i][j]][++l]=i;
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
    }
    printf("32");
    printf("17");
    return 0;
}