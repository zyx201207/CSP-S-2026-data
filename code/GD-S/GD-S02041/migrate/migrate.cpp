#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int c,T,n,d,a[N],s,t,len[N],ans,dis[N],minn=1e18;
vector<pair<int,int>> g[N];
bool bfs(int s,int t)
{
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=1;
	q.push(s);
	int minn=1e9,cnt=1;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		if (x==t)
		{
			if (dis[x]<minn)
			{
				minn=dis[x];
				cnt=1;
			}
			else if (dis[x]==minn) cnt++;
			continue;
		}
		for (auto t:g[x])
		{
			int v=t.first,w=t.second;
			if (dis[v]>=dis[x]+1 && w<=d)
			{
				dis[v]=dis[x]+1;
				q.push(v);
			}
		}
	}
	return cnt==2;
}
void solve1()
{
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			g[a[i]].push_back({a[j],abs(a[j]-a[i])});
		}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			if (bfs(i,j))
			{
//					cout<<i<<' '<<j<<endl;
				ans++;
			}
		}
	cout<<ans<<endl;
	ans=0;
	minn=1e18;
	for (int i=1;i<=n;i++) g[i].clear();
}
void solve2()
{
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			cout<<0<<endl;
		}
			
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while (T--)
	{
		cin>>n>>d;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		if (n<=5000) solve1();
		else solve2();
	}
	return 0;
} 
