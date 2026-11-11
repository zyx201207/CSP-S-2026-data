#include <bits/stdc++.h>
#define ll long long
using namespace std;

int MAXAI = 1 << 30;
int n, m;
int ans = 0;
int max_val = 0;

vector<int> g;
vector<bool> vis(MAXAI, false);

void dfs(int pos, int t) //0
{
	if (pos == m)
	{
		ans = max(ans, t);
		return;
	}
	
	for (int i : g)
	{
		if (vis[i])
		{
			continue;
		}
		//cout << "i" << i << " ";
		
		int n_t = t & i; 
		if (pos == 0)
		{
			n_t = i;
		}
		
		vis[i] = true;
		dfs(pos + 1, n_t);
		vis[i] = false;
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		
		//cout << x << endl;
		max_val = max(x, max_val);
		g.push_back(x);
	}
	
	dfs(0, 1);
	//cout << "h" << endl;
	
	cout << ans;
	return 0;
}
