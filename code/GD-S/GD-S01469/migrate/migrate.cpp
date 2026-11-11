#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 5010
#define pii pair<int,int>
#define fi first
#define se second
int n,d,a[N];
int cnt[N];bool v[N];
vector<int>e[N];
int bfs(int s)
{
	int res=0;
	for(int i=1;i<=n;i++)cnt[i]=v[i]=0;
	queue<int>q;q.push(s);
	while(!q.empty())
	{
		queue<int>qq;
		while(!q.empty())
		{
			int x=q.front();q.pop();
			cnt[x]++;
			for(int y:e[x])if(!v[y])qq.push(y);
		}
		while(!qq.empty())
		{
			int x=qq.front();qq.pop();
			v[x]=1;q.push(x);
		}
	}
	for(int i=1;i<=n;i++)res+=(cnt[i]==2);
	return res;
}
void solve()
{
	for(int i=1;i<=n;i++)e[i].clear();
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=d)
			{
				e[i].push_back(j);
			}
		}
	}
	int ans=0;
	for(int i=1;i<n;i++)ans+=bfs(i); 
	printf("%lld\n",ans);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;scanf("%lld%lld",&c,&t);
	while(t--)solve();
	return 0;
}
