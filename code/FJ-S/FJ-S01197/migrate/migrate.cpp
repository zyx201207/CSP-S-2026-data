#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c,t;
ll n,d,a[2000005],dx[2000005],ans;
bool vis[5005];
vector <int> g[5005];
struct node
{
	int id,step;
};
bool bfs(int st,int ed)
{
	int cnt = 0,step = 0;
	queue <node> q;
	q.push({st,0});
	vis[st] = 1;
	while(!q.empty())
	{
		node u = q.front();
		q.pop();
		if(u.id == ed) 
		{
			if(step == 0) step = u.step;
			if(u.step == step) cnt++;
		}	
		for(int v : g[u.id])
			if(!vis[v])
			{
				vis[v] = 1;
				q.push({v,u.step+1});
			}
	}
	return (cnt == 2);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
			cin >> a[i],dx[i] = a[i]-a[i-1];
		ll bothd = dx[2];
		bool flag = 1;
		for(int i = 2;i <= n;i++)
			if(dx[i] != n) flag = 0;
		if(flag) {cout << n-2*d/bothd+1 << endl;}
		else
		{
			ans = 0;
			memset(vis,0,sizeof vis);
			for(int i = 1;i <= 5000;i++) g[i].clear();
			for(int i = 1;i <= n;i++)
			{
				cin >> a[i];
				for(int j = 1;j < i;j++)
					if(dx[i]-dx[j] <= d) 
						g[i].push_back(j),g[j].push_back(i);
			}
			for(int i = 1;i <= n;i++)
				for(int j = i;j <= n;j++)
					if(bfs(i,j)) ans++;
			cout << ans << endl;	
		}
	}
	return 0;
}