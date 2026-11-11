#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
int n,k,p[15],dis[15];
bool f[15];
bool fll = 1;
void dfss(int x,int sum,int fa,bool fl,int cnt)
{
	if(!fll)
	{
		return;
	}
	if(!fl && f[x])
	{
		cnt++;
		if(cnt > 1)
		{
			fll = 0;
			return;
		}
	}
	fl = f[x];
	dis[x] = min(dis[x],sum);
	for(auto i : v[x])
	{
		if(i == fa)
		{
			continue;
		}
		dfss(i,sum + 1,x,fl,cnt);
	}
}
int ans = 2e9;
void dfs(int step)
{
	if(step > k)
	{
		for(int i = 1;i <= n;i++)
		{
			dis[i] = 2e9;
			f[i] = 0;
		}
		for(int i = 1;i <= k;i++)
		{
			f[p[i]] = 1;
		}
		for(int i = 1;i <= k;i++)
		{
			fll = 1;
			dfss(p[i],0,0,1,0);
			if(!fll)
			{
				return;
			}
		}
		int mx = 0;
		for(int i = 1;i <= n;i++)
		{
			mx = max(dis[i],mx);
		}
		ans = min(ans,mx);
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(i <= p[step - 1])
		{
			continue;
		}
		p[step] = i;
		dfs(step + 1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin >> C >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1;i <= n;i++)
		{
			v[i].clear();
		}
		for(int i = 1;i < n;i++)
		{
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans = 2e9;
		dfs(1);
		cout << ans << "\n";
	}
	return 0;
}
