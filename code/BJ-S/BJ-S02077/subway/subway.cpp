#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
long long p[500010],dis[510][510];
int n,m,q,k;
int h[500010][30];
long long b[500010][30];
int cnt[500010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    scanf("%d%d%d%d%d",&c,&m,&n,&k,&q);
    for(int i=1;i<=n;i++)   scanf("%lld",&p[i]);
    for(int i=1;i<=m;i++)
    {
        int l;
        scanf("%d",&l);
        for(int j=1;j<=l;j++)
        {
            int x;
            long long d;
            scanf("%d%lld",&x,&d);
            h[x][++cnt[x]]=i;
            b[x][cnt[x]]=d;
        }
        //cout << last << " " << fir << endl;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dis[i][j]=1e18;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cnt[i];j++)
        {
            for(int l=j+1;l<=cnt[i];l++)
            {
                dis[h[i][j]][h[i][l]]=min(dis[h[i][j]][h[i][l]],b[i][j]+b[i][l]);
                dis[h[i][l]][h[i][j]]=min(dis[h[i][l]][h[i][j]],b[i][j]+b[i][l]);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==j)    continue;
            for(int l=1;l<=m;l++)
            {
                long long ist=dis[j][i]+dis[i][l];
                if(ist<dis[j][l])   dis[j][l]=ist;
            }
        }
    }
    while(q--)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        long long minn=1e18;
        for(int i=1;i<=cnt[s];i++)
        {
            for(int j=1;j<=cnt[t];j++)
            {
                minn=min(minn,dis[h[s][i]][h[t][j]]+b[s][i]+b[t][j]);
            }
        }
        printf("%lld\n",minn+p[s]+p[t]);
    }
    return 0;
}
