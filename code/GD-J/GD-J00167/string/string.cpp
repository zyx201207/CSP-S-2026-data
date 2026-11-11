#include <iostream>
#include <string>
using namespace std;
int n;
string s;
long long ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		while (a--)
		{
			s += c;
		}
	}
	int len = s.length();
	int len1 = len / 2;
	for (int i = 0; i < len1; i++)
	{
		if (s[i] != s[len - i - 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
