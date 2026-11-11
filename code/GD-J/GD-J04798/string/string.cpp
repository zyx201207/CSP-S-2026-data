#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	for(int i = 1 ; i <= n ; i++)
	{
		int a;
		cin >> a;
		string ss;
		cin >> ss;
		for(int j = 1 ; j <= a ; j++)
		{
			s = s + ss;
		}
	}
	int len = s.size();
	int l = 0, r = len - 1;
	int sum = 0;
	while(true)
	{
		if(s[l] == s[r])
		{
			l++;
			r--;
		}
		else
		{
			sum++;
			l++;
			r--;
		}
		if(l == r || l + 1 == r)
		{
			break;
		}
	}
	cout << sum << endl;
	return 0;
} 
