#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],p,ys=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i<=n; i++)cin >> a[i];
	sort(a+1,a+n+1);
	while(true)
	{
		p = a[ys+1]-a[ys];
		if(m>=ys*p)
		{
			m-=ys*p;
			ys++;
		}
		else
		{
			cout << ys;
			return 0;
		}
	}
}
