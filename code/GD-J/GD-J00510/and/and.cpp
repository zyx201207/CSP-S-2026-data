#include <bits/stdc++.h>
using namespace std;
long long a[100005],ans;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		ans = max(ans,(a[i + 1] & a[i]));
	}
	cout << ans;
	return 0;
} 
