#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	ans = a[n];
	for (int i = n - 1;i > n - m;i--)
	{
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
