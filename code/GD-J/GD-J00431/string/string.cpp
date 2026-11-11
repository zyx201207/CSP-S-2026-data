#include<iostream>
#include<cstdio>
using namespace std;
const int N = 2e5+5;
pair<long long, char> a[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, i, l, r, ans=0;
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;
	l = 1;
	r = n;
	while(l < r)
	{
		if(a[l].second != a[r].second)
			ans += min(a[l].first, a[r].first);
		if(a[l].first == a[r].first)
		{
			l++;
			r--;
		}
		else if(a[l].first < a[r].first)
		{
			a[r].first -= a[l].first;
			l++;
		}
		else
		{
			a[l].first -= a[r].first;
			r--;
		}
	}
	cout << ans;
	return 0;
} 
