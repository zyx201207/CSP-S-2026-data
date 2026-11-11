#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n, k;
vector<int> g[N];
void dfs(int u, int s, int t)
{
//	for(int )
}
bool ck(int x)
{
	dfs(1, 0, x);
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		cout << n-k;
	}
	
	return 0;
}
