#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	long long n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n+1);
	long long ans = (a[n]&a[n-1]);
	for(int i = m;i >= 3;i--)
	{
		ans = (ans&a[i]);
	}
	cout << ans;
	return 0;
}
