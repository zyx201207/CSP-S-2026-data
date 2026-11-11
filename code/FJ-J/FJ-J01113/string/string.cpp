#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n, sum = 0, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		sum += a;
		for(int j = 1; j <= a; j++)
		{
			s += c;
		}
 	}
	for(int i = 0; i < sum/2; i++)
	{
		if(s[i] != s[sum - i - 1])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
