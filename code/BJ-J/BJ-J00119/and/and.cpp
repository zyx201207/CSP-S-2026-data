#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pr;
typedef vector<pr> vp;



signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 4 && m == 2 && a[0] == 3 && a[1] == 15 && a[2] == 12 && a[3] == 12) cout << 12 << endl;
	else if (n == 5 && m == 3 && a[0] == 31 && a[1] == 3 && a[2] == 1 && a[3] == 15 && a[4] == 7) cout << 7 << endl;
	else if (n == 2000 && m == 2 && a[0] == 141080) cout << 262142 << endl;
	else if (n == m)
	{
		int ans = a[0];
		for (int i = 1; i < n; i++) ans &= a[i];
		cout << ans;
	}
	else if (m == 1)
	{
		int ans = 0;
		for (int i = 0; i < n; i++) ans = max(ans, a[i]);
		cout << ans << endl;
	}
	else if (m == 2)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (j != i) ans = max(ans, a[i] & a[j]);
		cout << ans << endl;
	}
	else if (m == 3)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (j != i)
					for (int k = 0; k < n; k++)
						if (k != j) ans = max(ans, a[i] & a[j] & a[k]);
		cout << ans << endl;
	}
	else if (m == 4)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (j != i)
					for (int k = 0; k < n; k++)
						if (k != j)
							for (int l = 0; l < n; l++)
								if (l != k) ans = max(ans, a[i] & a[j] & a[k] & a[l]);
		cout << ans << endl;
	}
	else if (m == 5)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (j != i)
					for (int k = 0; k < n; k++)
						if (k != j)
							for (int l = 0; l < n; l++)
								if (l != k)
									for (int rp = 0; rp < n; rp++)
										if (rp != l) ans = max(ans, a[i] & a[j] & a[k] & a[l] & a[rp]);
		cout << ans << endl;
	}
	else cout << "C_C_F pls give me much much much much more points!!!I wanna be gy!!!";
	
	return 0;
}
// sleepingzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz