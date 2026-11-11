#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
long long m,a[maxn],b[maxn];
int check(int x)
{
	for(int i = x;i <= n;i++)
	{
		if(a[i] * x - (b[i] - b[i-x]) <= m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++) b[i] = b[i-1] + a[i];
	int l = 1,r = n;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1;
	return 0;
}
