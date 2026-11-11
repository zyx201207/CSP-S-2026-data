#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum;
	cin >> n;
	vector <char> s;
	for(int i = 1;i <= n;i++)
	{
		int x;
		char y;
		cin >> x >> y;
		for(int j = 1;j <= x;j++)
		{
			s.push_back(y);
		}
		sum += x;
	}
	int ans = 0;
	for(int i = 0;i < sum / 2;i++)
	{
		if(s[i] != s[sum - i - 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
