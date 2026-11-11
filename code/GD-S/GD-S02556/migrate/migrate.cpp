#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;


const long long N = 1e6+5;//?
vector<long long >g[N];
long long dis[N],vis[N],a[N],sum[N]; 
long long n,d;

long long ans = 0;

void dfs(long long st,long long now)
{
	queue<long long>q;
	q.push(st);
	while(!q.empty())
	{
		long long now = q.front();
		q.pop();
		//cout << "now:" << now << " dis:" << dis[now] << " sum:" << sum[now] << endl;
		for(auto i : g[now])
		{
			if(vis[i] == 0 && i > now)
			{
				sum[i] = 1;
				vis[i] = 1;
				dis[i] = dis[now] + 1;
				q.push(i);	
			}
			else
			{
				if(dis[now] + 1 == dis[i] && sum[i] == 1)
				{
					//cout << "finding:" << st  << " to " << i << endl;
					sum[i]++;
					ans++;
					q.push(i);	
				}
				else if(dis[now] + 1 == dis[i] && sum[i] == 2)
				{
					//cout << "finding_error:" << st  << " to " << i << endl;
					ans--;
					sum[i]++;
					q.push(i);	
				}
			}
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
	long long T,Q;
	cin >> T >> Q;
	while(Q--)
	{
		memset(a,0,sizeof a);
		for(long long i = 0;i<=5005;i++)g[i].clear();
		
		//³õÊ¼»¯ 
		cin >> n >> d;
		for(long long i = 1;i<=n;i++)
		{
			cin >> a[i];
		}
		for(long long i = 1;i<=n;i++)
		{

			long long j = i+1;
			while(a[j] - a[i] <= d && j <= n)
			{
				g[i].push_back(j);
				g[j].push_back(i); 
				j++;
			}
		}
			ans = 0;
			for(long long i = 1;i<=n;i++)
			{
				memset(vis,0,sizeof vis);
				memset(sum,0,sizeof sum);
				memset(dis,0,sizeof dis);
				dfs(i,i);
			} 
			cout << ans << endl;
	}
	return 0;
 } 
 //40pts
