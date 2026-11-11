#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n, m, a[N];

int count(int x)
{
	int ret = 0;
	while (x)
	{
		++ret;
		x &= (x - 1);
	}
	return ret;
}


//  ===================   solu:  n <= 20  ===========================
int ans;
bool vis[N];

void dfs(int k, int p, int cnt)
{
	if (k >= m)
	{
		ans = max(ans, cnt);
		return ;
	}
	for (int i = p; i <= n; ++i)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(k + 1, i, cnt & a[i]);
			vis[i] = 0;
		}
	}
}

void solu_dfs()
{
	for (int i = 1; i <= n; ++i)
	{
		vis[i] = 1;
		dfs(1, i, a[i]);
		vis[i] = 0;
	}
	cout << ans;
}
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


//  ===================   solu:  flag A  ===========================
void solu_A()
{
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, a[i]);
	cout << ans;
}
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// =====================  solu:  flag B  =============================
void solu_B()
{
	int ans = a[n];
	for (int i = n; i >= (n - m + 1); --i)
		ans &= a[i];
	cout << ans;
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// ==================  solu:  m == n =================================
void solu_M()
{
	int ans = a[1];
	for (int i = 1; i <= n; ++i)
		ans &= a[i];
	cout << ans;
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//  ====================  solu:  n <= 2000 && m == 1  ===============
void solu_n2000m1()
{
	int ans = a[1];
	for (int i = 1; i <= n; ++i)
		ans = max(ans, a[i]);
	cout << ans;
}
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//  ====================  solu:  n <= 2000 && m == 2  ===============
void solu_n2000m2()
{
	int ans = a[1] & a[2];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j) continue;
			ans = max(ans, a[i] & a[j]);
		}
	}
	cout << ans;
}
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	bool flag_DFS = 1, flag_A = 1, flag_B = 1;
	
	cin >> n >> m;
	if (n > 20) flag_DFS = 0;
	if (count(n) != 1) flag_B = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (flag_A && count(a[i] + 1) != 1) flag_A = 0;
		if (flag_B && a[i] != (i - 1)) flag_B = 0;
	}
	
	if (m == n) solu_M();
	else if (n <= 2000 && m <= 2)
	{
		if (m == 1) solu_n2000m1();
		else if (m == 2) solu_n2000m2();
	}
	else if (flag_DFS) solu_dfs();
	else if (flag_A) solu_A();
	else if (flag_B) solu_B();
	else cout << "CSP-S rp++";
	return 0;
}
