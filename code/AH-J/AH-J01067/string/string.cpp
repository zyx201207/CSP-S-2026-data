#include <bits/stdc++.h>
#define int long long
#define N 200010
using namespace std;

int a[N];
char c[N];
int n;
int answer = 0;

void solve(int l, int r)
{
}

signed main()
{
	freopen("string.in",  "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	
	int l = 1, r = n;
	while (l <= r)
	{
		if (a[l] <= 0) l++;
		if (a[r] <= 0) r--;
		int min_length = min(a[l], a[r]);
		
		a[l] -= min_length;
		a[r] -= min_length;
		
		if (c[l] != c[r])
		{
			answer += min_length;
		}
	}
	cout << answer;
	return 0;
}
