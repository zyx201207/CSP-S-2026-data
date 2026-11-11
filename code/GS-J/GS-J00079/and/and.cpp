#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int maxn[1000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans = a[n-m+1];
	for (int i = n-m+2;i<=n;i++)
	{
		ans and a[i];
	}
	cout << ans;
	return 0;
}
