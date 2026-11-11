#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, a[N], ans;
char c[N];
void cl(int i, int j, bool f)
{
	if(a[i] >= a[j])
	{
		if(f) ans += a[j];
		a[i] -= a[j];
		a[j] = 0;
	}else{
		if(f) ans += a[i];
		a[j] -= a[i];
		a[i] = 0;
	}
}
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i] >> c[i];
	int j = n;
	for(int i = 1; i <= n && i < j; i ++)
	{
		while(a[i] > 0 && i < j)
		{
			if(c[i] != c[j]) cl(i, j, 1);
			else cl(i, j, 0);
			if(a[j] == 0) j --;
		}
	}
	cout << ans << "\n"; 
	return 0;
}

