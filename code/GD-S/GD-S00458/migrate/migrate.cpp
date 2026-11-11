#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,inf=1e13;
int c,t,n,D,x[N],d[N],f[N],vis[N],cnt[N];
int ans;
vector<int> e[N];
queue<int> q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>D;
		ans=0;
		for(int i=1;i<=n;i++)  
		{
			cin>>x[i];
			e[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)  continue;
				if(abs(x[i]-x[j])<=D)  
				{
					e[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)  
			{
				d[j]=inf;
				vis[j]=0;
				cnt[j]=0;
				f[j]=0;
			}
			d[i]=0;
			f[i]=1;
			q.push(i);
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				if(vis[u])  continue;
				vis[u]=1;
				for(int v:e[u])
				{
					if(d[v]>d[u]+1)  
					{
						d[v]=d[u]+1;
						f[v]+=f[u];
						if(f[v]>inf)  cnt[v]=1,f[v]-=inf;
						q.push(v);
					}
					else  if(d[v]==d[u]+1)
					{
						f[v]+=f[u];
						if(f[v]>inf)  cnt[v]=1,f[v]-=inf;
					}
				}
			}
			for(int j=i+1;j<=n;j++)
			{
				if(f[j]==2&&!cnt[j])  ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
