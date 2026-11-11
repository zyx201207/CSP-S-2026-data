#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct Node
{
	int a;
	char c;
} s[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i].a >> s[i].c;
	}
	int l = 1, r = n;
	long long ans = 0;
	while (l < r)
	{
		//cout << l << " " << r << " " << min(s[l].a, s[r].a) << "\n";
		if (s[l].c != s[r].c)
		{
			ans += 1ll * min(s[l].a, s[r].a);
		}
		if (s[l].a < s[r].a)
		{
			s[r].a -= s[l++].a;
		}
		else if (s[l].a > s[r].a)
		{
			s[l].a -= s[r--].a;
		}
		else l++, r--;
	}
	cout << ans << "\n";
	return 0;
}
