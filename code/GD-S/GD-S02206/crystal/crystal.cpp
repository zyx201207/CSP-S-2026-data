#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005];
int n, m;
bool check(int t)
{
	for(int i = t;i <= n;i++)
	{
		if(t*a[i]-b[i]+b[i-t]<=m)return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		b[i]=a[i]+b[i-1];
	}
	int l = 1,r = n,mid = (l+r)/2;
	while(l < mid)
	{
		if(check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
		mid = (l+r)/2;
	}
	cout << l;
	return 0; 
}
