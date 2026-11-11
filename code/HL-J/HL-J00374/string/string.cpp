#include<bits/stdc++.h>
using namespace std;
long long n, a[232323], ans, l, r;
char ch[232323];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> ch[i];
	l = 0, r = n - 1;
	while(l <= r) 
	{
		long long mn = min(a[l], a[r]);
		if(ch[l] != ch[r])
			ans += mn;
		a[l] -= mn, a[r] -= mn;
		if(a[l] <= 0)
			l++;
		if(a[r] <= 0)
			r--;
	}
	cout << ans;
	return 0;
} 
