#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct str
{
	long long x;
	string s;
} a[N];

int n, m, cnt[50];
long long ans;

bool cmp(str p, str q)
{
	return p.s > q.s;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].x; a[i].s = "";
		long long tmp = a[i].x, idx = 0;
		for(int j = 0; j <= 30; j++) a[i].s += '0';
		while(tmp)
		{
			a[i].s[idx++] = tmp % 2 + '0';
			tmp >>= 1;
		}
		for(int j = 0; j <= 30; j++)
			if(a[i].s[j] == '1') cnt[j]++;
	}
	vector<int> v;
	for(int i = 0; i <= 30; i++)
		if(cnt[i] >= m) v.push_back(i);
	for(int i = 1; i <= n; i++)
	{
		string s = "";
		for(int j : v) s += a[i].s[j];
		reverse(s.begin(), s.end());
		a[i].s = s;
	}
	sort(a + 1, a + n + 1, cmp);
	
	ans = a[1].x;
	for(int i = 2; i <= m; i++) ans &= a[i].x;
	cout << ans << endl;
	return 0;
}
