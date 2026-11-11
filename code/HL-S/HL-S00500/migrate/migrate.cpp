#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int c,t,n,d,x[2000005],dis[2000005],ans[2000005];
inline void bfs(int s)
{
	for(int i=1;i<=n;i++) dis[i] = LLONG_MAX,ans[i] = 0;
	dis[s] = 0;
	ans[s] = 1;
	queue <pii> q;
	q.push({s,0});
	while(q.size())
	{
		int f = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for(int i=f+1;i<=n;i++)
		{
			if(x[i] - x[f] > d) break;
			if(dis[i] > cnt + 1)
			{
				ans[i] = ans[f];
				dis[i] = cnt + 1;
			}
			else if(dis[i] == cnt + 1)
			{
				ans[i] += ans[f];
			}
			q.push({i,cnt+1});
		}
	}
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++)
			{
				if(ans[j] == 2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}