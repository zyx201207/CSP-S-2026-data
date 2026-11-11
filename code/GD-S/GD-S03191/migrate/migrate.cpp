#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int n,T,C,d[N],f[N],du[N],rd[N];
ll D,x[N],ans;
vector<int> g[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%lld",&n,&D);
		for(int i=1;i<=n;i++) g[i].clear();
		memset(du,0,sizeof(du));
		ans=0;
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=n-1;i>0;i--)
		{
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=D) g[i].push_back(j),du[j]++;
			memcpy(rd,du,sizeof(rd));
			memset(d,0x3f,sizeof(d));
			for(int i=1;i<=n;i++) f[i]=1;
			queue<int> q;
			q.push(i),d[i]=0;
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				for(int k=0;k<g[u].size();k++)
				{
					int v=g[u][k];
					rd[v]--;
					if(d[v]>d[u]+1) d[v]=d[u]+1,f[v]=f[u];
					else if(d[v]==d[u]+1) f[v]+=f[u];
					if(!rd[v]) q.push(v);
				}
			}
			for(int k=i+1;k<=n;k++) if(f[k]==2) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//40pts?
