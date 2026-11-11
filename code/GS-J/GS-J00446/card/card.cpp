#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
constexpr int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], stk[N], top, pos[N], ans[N], last[M];
vector<int> x[M];
void solve(int r) // 第 r 伦
{
	top = 0; // 栈重置
	for (int i = r; i <= n; i++)
	{
		if (!pos[a[i]])
		{
			stk[++top] = a[i];
			pos[a[i]] = top;
		}
		else
		{
			int x = pos[a[i]];
			for (int j = x; j <= top; j++)
			{
				pos[stk[j]] = 0;
			}
			top = x - 1;
			stk[++top] = a[i];
			pos[a[i]] = top;
		}
	} 
	for (int i = 1; i <= top; i++)
	{
		int x = stk[i];
		ans[x]++;
		pos[x] = 0;
	}
} 
void solveA()
{
	top = 0;
	vector<int> diff(m + 1);
	for (int i = n; i >= 1; i--)
	{
		if (i == n)
		{
			stk[++top] = a[i];
			diff[stk[top]]++;
			if (stk[1] + 1 <= m) diff[stk[1] + 1]--;
		}
		else
		{
			if (a[i] != a[i + 1])
			{
				stk[++top] = a[i];
			}
			diff[stk[top]]++;
			if (stk[1] + 1 <= m) diff[stk[1] + 1]--;
		}
	}
	for (int i = 1; i <= m; i++) diff[i] += diff[i - 1];
	for (int i = 1; i <= m; i++) ans[i] = diff[i];
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	bool ok = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] < a[i - 1])
		{
			ok = 0;
		}
	}
	if (n <= 5000)
	{
		for (int i = 1; i <= n; i++)
		{
			solve(i);
		}
	}
	else if (ok) 
	{
		solveA();
	}
	else
	{
		for (int i = 1; i <= n; i++) 
		{
			last[a[i]] = i;
		}
		for (int i = n; i >= 1; i--)
		{
			int nl = i, nr = last[a[i]]; // 一个新的区间
			ans[a[i]]++;
			int now = nr + 1;
			while (now <= n)
			{
				ans[a[now]]++;
				now = last[a[now]] + 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0; 
}
