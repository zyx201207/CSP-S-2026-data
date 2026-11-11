#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
struct
{
	long long cnt;
	string s;
}a[N];
long long ans = 0 , ans2 = 0 , all = 0 , len;
string a1 , a2 , str;

int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> a[i].cnt >> a[i].s;
		all += a[i].cnt;
	}
	a1 = a[0].s;
	a2 = a1;
	for (int i = 0 ; i < n ; i ++)
	{
		if (a[i].s != a1)
		{
			ans += a[i].cnt;
		}
	}
	if (all >= 1000000005)
	{
		cout << ans << '\n';
		return 0;
	}
	for (int i = 0 ; i < n ; i ++)
	{
		for (int j = 0 ; j < a[i].cnt ; j ++)
		{
			str = str + a[i].s;
		}
	}
	len = str.size();
	for (int i = 0 ; i < (len >> 1) + 1 ; i ++)
	{
		if (str[i] != str[n - 1 - i])
		{
			ans2 ++;
		}
	}
	cout << min(ans , ans2) << '\n';
	
	return 0;
}
