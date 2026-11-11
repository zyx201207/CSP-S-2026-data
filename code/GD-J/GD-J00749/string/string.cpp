#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 10;
int n,a[N];
char c[N];

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i] >> c[i];
	int l = 1,r = n,ans = 0;
	while (l <= r)
	{
		if (a[l] == a[r])
		{
			if (c[l] != c[r]) ans += a[l];
			l ++,r --;
		}
		else if (a[l] > a[r])
		{
			if (c[l] != c[r]) ans += a[r];
			a[l] -= a[r];
			r --;
		}
		else
		{
			if (c[l] != c[r]) ans += a[l];
			a[r] -= a[l];
			l ++;
		}
	}
	cout << ans << endl;
	return 0;
 } 
 
 
 

