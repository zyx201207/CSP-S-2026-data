#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
constexpr int N(2e5 + 10);
struct str
{
	int a;
	char c;
} l[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i].a >> l[i].c;
	}
	int i = 1, j = n;
	long long ans = 0;
	while (i <= j)
	{
		if (l[i].c == l[j].c)
		{
			if (l[i].a > l[j].a)
			{
				l[i].a -= l[j].a;
				l[j].a = 0;
				j--;
			}
			else if (l[i].a < l[j].a)
			{
				l[j].a -= l[i].a;
				l[i].a == 0;
				i++;
			}
			else
			{
				l[i].a = l[j].a = 0;
				i++;
				j--;
			}
		}
		else
		{
			if (l[i].a > l[j].a)
			{
				ans += l[j].a;
				l[i].a -= l[j].a;
				l[j].a = 0;
				j--;
			}
			else if (l[i].a < l[j].a)
			{
				ans += l[i].a;
				l[j].a -= l[i].a;
				l[i].a == 0;
				i++;
			}
			else
			{
				ans += l[i].a;
				l[i].a = l[j].a = 0;
				i++;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
}
