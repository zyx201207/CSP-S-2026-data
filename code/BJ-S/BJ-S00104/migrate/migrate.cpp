#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,x[2000005],minn,cnt,ans;
void dfs(int l,int v,int step)
{
    if(l==v)
    {
        cnt+=(step==minn);
        return;
    }
    for(int i=l+1;i<=v&&x[i]-x[l]<=d;i++)//枚举飞到的点
        dfs(i,v,step+1);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--)
    {
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",&x[i]);
        for(int u=1;u<=n;u++)
            for(int v=u+1;v<=n;v++)
            {
                minn=0,cnt=0;
                for(int i=u,j;i<=v;i++)
                {
                    for(j=i;j<=v&&x[j+1]-x[i]<=d;j++);
                    i=j,minn++;
                }
                dfs(u,v,0);
                ans+=(cnt==2);
            }
        printf("%lld\n",ans);
    }
    return 0;
}
