#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long a[100005];
	char c[100005];
	string s ="";
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= a[i];j++)
		{
			s+=c[i];
		}
	}
	int l = 0, r = s.size()-1;
	long long cnt = 0;
	while(l < r)
	{
		if (s[l]!=s[r])
		{
			cnt++;
		}
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}
