#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=(2e6+5),INF=LLONG_MAX/3;
LL c,T,n,k,g,dis[N],r,ans=INF;
bool b[N],vis[N];
vector<LL>G[N];
inline LL read(){
	LL ans=0,neg=1;
	char c=getchar();
	while(c==' '||c=='\n'||c=='\r'){c=getchar();}
	if(c=='-')
	{neg=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+LL(c-'0');c=getchar();}
	return ans*neg;
}
queue<LL>q;
void dfs(LL u)
{
    if(!b[u])return;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        LL v=G[u][i];
        if(!vis[v]&&b[v])dfs(v);
    }
}
LL popcnt(LL x)
{
    LL cnt=0;
    while(x)
    {
        cnt+=(x&1);
        x>>=1;
    }
    return cnt;
}
void bfs()
{
    while(!q.empty())
    {
        LL u=q.front();q.pop();r=max(r,dis[u]);
        for(int i=0;i<G[u].size();i++)
        {
            LL v=G[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
   freopen("hub.in","r",stdin);
   freopen("hub.out","w",stdout);
    c=read();T=read();
    while(T--)
    {
        n=read();k=read();r=0;ans=INF;g=INF;
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<n;i++)
        {
            LL u=read(),v=read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(n<=10)
        {
            for(int s=0;s<(1<<n);s++)
            {
                r=0;
                if(popcnt(s)==k)
                {
                    int cnt=0;
                    for(int i=1;i<=n;i++)
                    {
                        b[i]=((s>>(i-1))&1);
                        vis[i]=0;dis[i]=INF;
                    }
                    for(int i=1;i<=n;i++)
                    {
                        if(b[i]&&!vis[i])cnt++,dfs(i);
                    }
                    if(cnt<=2)
                    {
                        while(!q.empty())q.pop();
                        for(int i=1;i<=n;i++)
                        {
                            if(b[i])q.push(i),vis[i]=1,dis[i]=0;
                            else vis[i]=0;
                        }
                    bfs();
                    if(r<ans)g=s;
                   // cerr<<s<<" "<<r<<endl;
                    ans=min(ans,r);
                    }
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
