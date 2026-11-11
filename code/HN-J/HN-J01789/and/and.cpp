#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travle.out","w",stdout);
	int n,m,a[200005],ans = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		if(a[i]&a[i+1])
		{
			ans += a[i];
		}
	}
	cout << ans;
} 
