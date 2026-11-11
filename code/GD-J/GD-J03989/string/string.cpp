#include <bits/stdc++.h>
using namespace std;
long long n, a, ans;
string s;
char c;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a >> c;
		while(a--)
			s += c;
	}
	for(long long i = 0; i < s.length() / 2; i++)
		if(s[i] != s[s.length() - i - 1])
			ans++;
	cout << ans << '\n';
	return 0;
}
