#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct str
{
	long long l, r;
} s[N];

int n, a[N];
long long ans, pref[N], b[N][30];
char c[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		s[i].l = s[i - 1].r + 1;
		s[i].r = s[i].l + a[i] - 1;
		pref[i] = pref[i - 1] + a[i];
		for(int j = 0; j < 26; j++) b[i][j] = b[i - 1][j];
		b[i][c[i] - 'a'] += a[i];
	}
	long long len = pref[n], ans = 0;
	for(int i = 1; i <= n; i++)
	{
		char ch = c[i];
		long long l = len - s[i].r + 1, r = len - s[i].l + 1;
		long long p = lower_bound(pref + 1, pref + n + 1, l) - pref;
		long long q = lower_bound(pref + 1, pref + n + 1, r) - pref;
		if(p == q)
		{
			if(c[p] != ch) ans += r - l + 1;
			continue;
		}
		for(int j = 0; j < 26; j++)
		{
			if(j == ch - 'a') continue;
			ans += b[q - 1][j] - b[p][j];
		}
		if(c[p] != ch) ans += s[p].r - l + 1;
		if(c[q] != ch) ans += r - s[q].l + 1; 
	}
	cout << ans / 2 << endl;
	return 0;
}
