#include<iostream>
#include<string>
using namespace std;
long long n, m, ans = 0;
char a;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> m >> a;
		for (int j = 1; j <= m; j++)
		{
			s += a;
		}
	}
	for (int i = 0; i < (s.size() / 2); i++)
	{
		if (s[i] != s[s.size() - i - 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
