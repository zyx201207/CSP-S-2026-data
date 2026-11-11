#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[5001],f[5001],cnt[5001];
vector<int>e[5001];
void bfs(int s)
{
	memset(f,-1,sizeof(f));
	queue <int> q;
	q.push(s);
	f[s]=0;
	cnt[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto i:e[x])
		{
			if(f[i]==-1)
			{
				cnt[i]=cnt[x];
				f[i]=f[x]+1;
				q.push(i);
			}
			else if(f[i]==f[x]+1)
			{
				cnt[i]+=cnt[x];
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;++i)
		{
			e[i].clear();
			cin>>a[i];
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				if(a[j]-a[i]<=d)
				{
					e[i].push_back(j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			bfs(i);
			for(int j=i+1;j<=n;++j)
			{
				if(cnt[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
