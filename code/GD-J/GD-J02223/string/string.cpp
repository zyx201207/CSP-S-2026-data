#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
constexpr int N = 2e5 + 5;
struct stu
{
	long long a;
	char c;
	stu() {}
	stu(const long long &a, const char &c) : a(a), c(c) {}
};
long long a[N], qzh[N], ans, n, nlen = 0, len = 0, f = 0, num, num2;
char c[N];
stack<stu> s, s2;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		f += a[i];
		qzh[i] = qzh[i - 1] + a[i];
	}
	len = f / 2;
	if (f % 2)
		len++;
	for (int i = 1; i < n; i++)
	{
		if (qzh[i] + 1 <= len && qzh[i + 1] >= len)
		{ 
			num = len - qzh[i];
			if (f % 2)
				num--;
			num2 = a[i + 1] - num;
			if (f % 2)
				num2--;
			if (num)
				s.emplace(num, c[i + 1]);
			if (num2)
				s2.emplace(num2, c[i + 1]); 
			nlen = i + 1;
			break;
		}
	}
	for (int i = nlen - 1; i >= 1; i--)
	{ 
		s.emplace(a[i], c[i]);
	}
	for (int j = nlen + 1; j <= n; j++)
	{
		s2.emplace(a[j], c[j]);
	}
	stu u, u2;
	while (!s.empty() && !s2.empty())
	{
		u = s.top();
		s.pop();
		u2 = s2.top();
		s2.pop();
		if (u.c != u2.c)
			ans += min(u.a, u2.a);
		if (u.a > u2.a)
			s.emplace(u.a - u2.a, u.c);
		else if (u.a < u2.a)
			s2.emplace(u2.a - u.a, u2.c);
	}
	cout << ans;
	return 0;
} 
