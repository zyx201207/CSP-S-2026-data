#include <bits/stdc++.h>
using namespace std;

string s,c;
unsigned long long n,a,ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= n;i ++)
	{
		cin >> a >> c;
		for (int j = 1;j <= a;j ++)
		{
			s += c;
		}
	}

	for (long long i = 0;i <= (s.size() - 1) / 2;i ++)
	{
		if (s[i] != s[s.size() - 1 - i]) ans ++;
	}
	
	cout << ans;

	return 0;
}
