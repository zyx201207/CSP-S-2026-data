#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],dis[2000005],f[2000005],in[2000005];
vector<int> b[2000005]; 
void topo(int s)
{
	queue<int> q;
	for(int i = s;i <= n;i++)
	{
		dis[i] = 1e18;
		f[i] = in[i] = 0;
	}
	for(int i = s;i <= n;i++)
	{
		for(auto j:b[i]) in[j]++;
	}
	for(int i = s;i <= n;i++)
	{
		if(!in[i]) q.push(i);
	}
	dis[s] = 0,f[s] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v:b[u])
		{
			if(dis[v] > dis[u]+1)
			{
				dis[v] = dis[u]+1;
				f[v] = f[u];
			}
			else if(dis[v] == dis[u]+1) f[v] += f[u];
			if(--in[v] == 0) q.push(v);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++) 
		{
			cin >> a[i];
			b[i].clear();
		}
		int ans = 0;
		if(c == 13 || c == 14)
		{
			for(int i = 1;i+3 <= n;i++)
			{
				if(a[i+3]-a[i] > d && (a[i+3]-a[i+2] <= d && a[i+2]-a[i] <= d) && (a[i+3]-a[i+1] <= d && a[i+1]-a[i] <= d)) ans++;
			}
			cout << ans << "\n";
		}
		else if(c <= 10)
		{
			for(int i = 1;i <= n;i++)
			{
				for(int j = i+1;j <= n;j++)
				{
					if(a[j]-a[i] <= d) b[i].push_back(j);
				}
			}
			for(int i = 1;i <= n;i++)
			{
				topo(i);
				for(int j = i+1;j <= n;j++) ans += (f[j] == 2); 
			}
			cout << ans << "\n";
		}
		else if(c == 11 || c == 12)
		{
			int k = a[2]-a[1];
			if(d < 2*k) cout << "0\n";
			else cout << max(0ll,n-(d/k+d/k-1)) << "\n";
		}
		else
		{
			vector<int> good;
			for(int i = 1;i+3 <= n;i++)
			{
				if(a[i+3]-a[i] > d && (a[i+3]-a[i+2] <= d && a[i+2]-a[i] <= d) && (a[i+3]-a[i+1] <= d && a[i+1]-a[i] <= d)) good.push_back(i+3);
			}
			good.push_back(n+1);
			int id = 0;
			for(int l = 1,r;l <= n;l = r+1)
			{
				r = l+1;
				while(r <= n && a[r]-a[r-1] <= d) r++;
				r--;
				for(int i = l;i <= r;i++)
				{
					while(good[id]-3 < i) id++;
					if(id < good.size()-1) ans += min(r,good[id+1]-1)-good[id]+1;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
