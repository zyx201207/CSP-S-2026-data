#include <stack>
#include <cstring>
#include <iostream>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], ans[N];
bool vis[N];
stack <int> s;

void play(int x)
{
	for (int i = x; i <= n; ++i)
	{
		while (s.size() && vis[a[i]])
		{
			vis[s.top()] = 0;
			s.pop();
		}
		vis[a[i]] = 1;
		s.push(a[i]);
	}
	while (s.size())
	{
		++ans[s.top()];
		vis[s.top()] = 0;
		s.pop();
	}
}

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++i)
		play(i);
	
	for (int i = 1; i < m; ++i)
		cout << ans[i] << ' ';
	cout << ans[m]; 
	return 0;
}
