#include <bits/stdc++.h>
using namespace std;

int n , m , ans = -9999;
long long s[1000005] , h[10000005],a[1000005];

int check(int x)
{
	long long q = 999999,p=999999;
	for ( int i = x ; i <= n ; i++)
	{
		for ( int k = 1 ; k < x,i+k<n ; k++)
		{
			if(a[i]*x-(h[i-x+1]-h[i+1])<=m)
				return true;
			if ((s[i+x-1]-s[i-1])-a[i]*x<=m)
				return true;
			if(a[i]*(k+1)-(h[i-k]-h[i+1])+(s[i+x-1-k]-s[i-1])-a[i]*(x-k)<=m)
				return true;
		} 
	}
	return q <= m;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for ( int i = 1 ; i <= n ;i++)
	{
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	for ( int i = n ; i >= 1 ; i--)
		h[i] = h[i+1] + a[i];
	int l = 1,r=n;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(check(mid))
		{
			l = mid+1 ;
			ans = max(ans,mid);
		}
		else
		{
			r = mid-1;
		}
	}
	cout << ans;
	return 0;
}
