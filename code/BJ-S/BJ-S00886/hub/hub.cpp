#include<bits/stdc++.h>
using namespace std;
int c__,T,n,m,cur,ans,f[30][30],a[30],b[30],c[30];
bool li[30][30],fla[30];
int fi_(int x){return (b[x]==x)?(x):(b[x]=fi_(b[x]));}
void dfs(int ste,int cnt)
{
    if(ste>n)
    {
        if(cnt==m)
        {
            memset(c,0,sizeof(c));
            for(int i=1;i<=n;i++)b[i]=i;
            int te=0,ret=0;
            for(int i=1;i<=cur;i++)
            {
                for(int j=1;j<=cur;j++)
                {
                    if(li[a[i]][a[j]])
                    {
                        int x=fi_(a[i]),y=fi_(a[j]);
                        b[x]=y;
                    }
                }
            }
            for(int i=1;i<=cur;i++)
            {
                int x=fi_(a[i]);
                c[x]++;
                if(c[x]==1)te++;
            }
            if(te<=2)
            {

                for(int i=1;i<=n;i++)
                {
                    int wu=1e9;
                    if(!fla[i])
                    {
                        for(int j=1;j<=cur;j++)wu=min(wu,f[i][a[j]]);
                        ret=max(ret,wu);
                    }
                }
                ans=min(ans,ret);
            }
        }
        return;
    }
    dfs(ste+1,cnt);
    if(cnt<m)
    {
        a[++cur]=ste,fla[ste]=true;
        dfs(ste+1,cnt+1);
        a[cur]=0,cur--,fla[ste]=false;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d %d",&c__,&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        if(n<=20)
        {
            memset(f,0x3f,sizeof(f));
            memset(li,0,sizeof(li));
            for(int i=1;i<=n;i++)f[i][i]=0;
            for(int i=1;i<n;i++)
            {
                int u,v;
                scanf("%d %d",&u,&v);
                f[u][v]=f[v][u]=1,li[u][v]=li[v][u]=true;
            }
            for(int k=1;k<=n;k++)
            {
                for(int i=1;i<=n;i++)
                {
                    if(i==k)continue;
                    for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
            cur=0,ans=1e9;
            dfs(1,0);
            printf("%d\n",ans);
        }
    }
    return 0;
}
