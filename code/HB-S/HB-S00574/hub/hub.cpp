#include<bits/stdc++.h>
using namespace std;
const int N=35,inf=0x3fffffff;
int c,T,n,k,tot;
bool bk[N],bk1[N];
vector<int> e[N];
void dfs(int x,int f,int dep)
{
    if(bk[x])
    {
        tot=min(tot,dep);
        return;
    }
    for(auto y:e[x])
    {
        if(y==f)continue;
        dfs(y,x,dep+1);
    }
}
void dfs1(int x)
{
    bk1[x]=1;
    for(auto y:e[x])
    {
        if(bk[y]&&!bk1[y])dfs1(y);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            e[i].clear();
        }
        int x,y;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        int ans=inf;
        for(int i=1;i<1<<n;i++)
        {
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                if(i>>j-1&1)
                {
                    bk[j]=1;
                    cnt++;
                }
                else
                {
                    bk[j]=0;
                }
                bk1[j]=0;
            }
            if(cnt!=k)continue;
            cnt=0;
            for(int j=1;j<=n;j++)
            {
                if(bk[j]&&!bk1[j])
                {
                    dfs1(j);
                    cnt++;
                }
            }
            if(cnt>2)continue;
            int tmp=0;
            for(int j=1;j<=n;j++)
            {
                tot=inf;
                dfs(j,0,0);
                tmp=max(tmp,tot);
            }
            // printf(">>%d:%d\n",i,tmp);
            ans=min(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}