#include<bits/stdc++.h>
using namespace std;
const int SIZ=2e6;
const long long INF=1e9;
int c,T,n,dis[SIZ];
long long lim,x[SIZ],cnt[SIZ],ans;
vector<int>e[SIZ];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>lim;ans=0;
		vector<vector<int>>e(n+1);
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1,l=1;i<=n;i++)
		{
			while(l<n&&x[l+1]-x[i]<=lim)l++;
			for(int j=l;j>i;j--)
			{
				e[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			queue<int>q;
			for(int j=1;j<=n;j++)dis[j]=INF,cnt[j]=0;
			q.push(i);cnt[i]=1;dis[i]=0;
			while(!q.empty())
			{
				int u=q.front();
				if(cnt[u]==2)ans++;
				q.pop();
				for(int v:e[u])
				{
					if(v==u+1)q.push(v);
					if(dis[v]==dis[u])continue;
					dis[v]=dis[u]+1;cnt[v]+=cnt[u];
				}
			}
		}
		cout<<ans<<"\n";
	}
}
