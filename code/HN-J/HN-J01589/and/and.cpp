#include <bits/stdc++.h>

using namespace std;

struct P
{
	int len, a;
	vector<int> s;
};

const int N = 2e5 + 10;
int n, m;
P a[N];

bool cmp (P q, P p)
{
	if (q.len != p.len)
	{
		return q.len > p.len;
	}
	else
	{
		return q.a > p.a;
	}
}

int main ()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int b, len = 0, c;
		cin >> b;
		c = b;
		vector<int> s(30);
		int z = 0;
		while (b)
		{
			s[z] = b % 2;
			z++;
			if (b % 2 == 1)
			{
				len++;
			}
			b /= 2;
		}
		a[i].len = len, a[i].s = s;
		a[i].a = c;
	}
	sort(a + 1, a + n + 1, cmp);
	int ans = INT_MAX;
	for (int i = 1; i <= m; i++)
	{
		ans &= a[i].a;
	}
	cout << ans << "\n";
	return 0;
} 
