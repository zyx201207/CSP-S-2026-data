#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#define int long long
#define endl "\n"
#define fi first
#define se second
using namespace std;
const int MAXN = 5e5 + 10;
int n, m;
int a[MAXN], ans[MAXN];
stack <int> st;
vector <int> vis(m + 10, 0);
void solve()
{
	for (int i = n; i >= 1; i--)
	{
		if (vis[ a[i] ] == true)
		{
			while (!st.empty() && st.top() != a[i])
			{
				vis[st.top()] = max(vis[st.top()] - 1, 0ll);
				st.pop();
			}
		} 
		else
		{
			st.push(a[i]);
			vis[ a[i] ]++;
		}
		for (int i = 1; i <= m; i++)    if (vis[i])    ans[i]++;
	}
	for (int i = 1; i <= m; i++)    cout << ans[i] << " \n"[i == m];
}
signed main()
{
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)    cin >> a[i];
	if (n * n * m >= 3e7)
	{
		solve();
		return 0;
	}
	for (int cur = 1; cur <= n; cur++)
	{
		stack <int> st; vector <int> vis(m + 10, 0);
		for (int i = cur; i <= n; i++)
		{
			// 将要打出点数为a[i]的牌
			if (vis[ a[i] ] == true)
			{
				while (!st.empty() && st.top() != a[i])
				{
					vis[st.top()] = max(vis[st.top()] - 1, 0ll);
					st.pop();
				}
				// 这样处理之后st.top()就会刚好为a[i]
				continue; 
			} 
			st.push(a[i]); vis[ a[i] ]++;
			
		} 
		for (int i = 1; i <= m; i++)    if (vis[i])    ans[i]++;
	}
	for (int i = 1; i <= m; i++)    cout << ans[i] << " \n"[i == m];
	return 0;
}

