#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,m,a[500050],ans,l,re;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
//	for(int i = 1;i <= n;i++)
//	{
//		cout << a[i] << " ";
//	}
	ans = l = 1;
	re = m-(a[2]-a[1]);
	for(int i = 2;i <= n;i++)
	{
		while(re < 0)
		{
			re += a[i] - a[l++];
		}
		re -= (a[i+1]-a[i]) * (i-l+1);
		ans = max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
