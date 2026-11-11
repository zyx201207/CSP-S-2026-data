#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2e6 + 10;
int c,t;
vector<int>g[MAXN];
vector<int>tmp;
vector<int>x;
/*void add(int u, int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}*/
/*void dfs(int u, int baba)
{
	tmp.push_back(u);
	//limits
	for(int v : g[u])
	{
		if(v == baba)dfs(v, u);
	}
	tmp.pop_back();	
}*/
bool isDouble(int u, int v, int w, int d)
{
	if((v - u) / w > d)return 0;
	else 
	{
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1;i <= x.size();i++)
		{
			int l = 0,j = 1;
			while(l <= d)
			{
				l += x[j + 1] - x[j];
				j++;
			}
			cnt1++;
			l = 0;
		}
		for(int i = 1;i <= x.size();i++)
		{
			int l = 1, j = 1;
			while(l <= d)
			{
				l += x[i + 1] - x[i];
				j++;
			}
			cnt2++;
		}
		if(cnt1 == cnt2)return 1;
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	cin >> c >> t;
	while(t--)
	{
		int n, d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)cin >> x[i];
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i;j <= n;i++)
			{
				//add(x[i], x[j]);
				if(isDouble(x[i], x[j], j - i, d))ans++;
			}
		}	
		cout << ans << '\n';
	}
	return 0;
}
