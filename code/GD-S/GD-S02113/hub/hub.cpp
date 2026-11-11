#include <bits/stdc++.h>
using namespace std;

vector<int> v[11];	
int dis[11];
bool f[11],vis[11];
int n,k;
int ans = 0,no = 0;

void dfs(int x)
{			
	vis[x] = 1;
	if(f[x]) dis[x] = 0;
	for(int i = 0;i < v[x].size();i++)
	{
		int y = v[x][i];
		if(!vis[y])	dfs(y);		
		dis[x] = min(dis[x],dis[y] + 1);
	} 
	no = max(no,dis[x]);
}

void xz(int step,int now)
{
	if(step == k) 
	{
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		no = 0;
		dfs(1);
		ans = max(ans,no);
		return;
	}
	if(now > n) return;
	f[now] = 1;
	xz(step + 1,now + 1);
	f[now] = 0;
	xz(step,now + 1);
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int j = 1;j <= t;j++)
	{
		cin >> n >> k;
		ans = 0;
		for(int i = 1;i <= n - 1;i++)
		{
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(n == k) 
		{
			cout << 0 << endl;
		}
		else if(n - k <= 3) cout << 1 << endl;
		else
		{
			xz(0,1);
			cout << ans << endl;
		}
		for(int i = 1;i <= n;i++)
		{
			while(!v[i].empty()) v[i].pop_back();
		}
	}
	return 0;
}

