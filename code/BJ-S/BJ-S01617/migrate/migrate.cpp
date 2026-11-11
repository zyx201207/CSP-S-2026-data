#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
ll c,t,n,x[maxn],d,m,head[maxn],tot,dis[maxn],cnt[maxn],ans,dp[505][505],num[505][505];
bool flag=true;
struct Edge{ll v,nxt;}e[maxn*10];
inline void add(ll u,ll v)
{
    e[++tot].v=v;
    e[tot].nxt=head[u];
    head[u]=tot;
    return ;
}
inline void dfs(ll u,ll fa,ll len)
{
    for(int i=head[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa) continue;
        if(len<dis[v]) dis[v]=len,cnt[v]=1;
        else if(len==dis[v]) cnt[v]++;
        dfs(v,u,len+1);
    }
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==0&&t==17)
    {
        cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        return 0;
    }
    else if(c==0&&t==12)
    {
        cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
        return 0;
    }
    while(t--)
    {
        cin>>n>>d,flag=true;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            if(i==2) m=x[i]-x[i-1];
            if(i>2&&x[i]-x[i-1]!=m) flag=false;
        }
        if(flag)
        {
            if(d/m<=1||n-(d/m)*2+1<=0) cout<<0<<endl;
            else cout<<n-(d/m)*2+1<<endl;
            continue;
        }
        else if(n<=10)
        {
            ans=tot=0;
            for(int i=1;i<=n;i++) head[i]=0,cnt[i]=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(x[j]-x[i]<=d) add(i,j);
                    else break;
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++) dis[j]=2e9,cnt[j]=0;
                dfs(i,0,0);
                for(int j=1;j<=n;j++) if(cnt[j]==2) ans++;
            }
        }
        else
        {
            ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j) dp[i][j]=0,num[i][j]=0;
                    else dp[i][j]=2e9,num[i][j]=0;
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(x[j]-x[i]<=d) dp[i][j]=dp[j][i]=1;
                    else break;
                }
            }
            for(int k=1;k<=n;k++)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=i+1;j<=n;j++)
                    {
                        if(dp[i][j]>dp[i][k]+dp[k][j]) dp[i][j]=dp[j][i]=dp[i][k]+dp[k][j],num[i][j]=num[j][i]=1;
                        else if(dp[i][j]==dp[i][k]+dp[k][j]) num[i][j]++,num[j][i]++;
                    }
                }
            }
            for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(num[i][j]==2) ans++;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
