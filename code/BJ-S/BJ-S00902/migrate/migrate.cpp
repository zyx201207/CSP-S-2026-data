#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010],cha[2000010],minn=2e9,dis[200010];
void dfs(int step,int cnt,int v)
{
    if(cnt>minn)return;
    if(step==v)
    {
        minn=min(minn,cnt);
        dis[cnt]++;
        return;
    }
    for(int i=step+1;i<=v;i++)
    {
        if(a[i]-a[step]>d)break;
        dfs(i,cnt+1,v);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--)
    {
        int ans=0;
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cha[i]=a[i]-a[i-1];
        }
        for(int u=1;u<=n;u++)
        {
            for(int v=u+2;v<=n;v++)
            {
                minn=2e9;
                memset(dis,0,sizeof dis);
                dfs(u,0,v);
                if(minn<2e9&&dis[minn]==2)ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
