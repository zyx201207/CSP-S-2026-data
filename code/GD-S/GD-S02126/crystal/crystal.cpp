#include<bits/stdc++.h>
#define int __int128
#define N 500005
using namespace std;

long long input;
int n,m,a[N],s[N];
bool check(int x)
{
	for (int i=x;i<=n;i++)
	{
		if (x*a[i]-(s[i]-s[i-x])<=m)
			return 1;		
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> input; n=input;
	cin >> input; m=input;
	for (int i=1;i<=n;i++)
	{
		cin >> input;
		a[i]=input;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout << (long long)r;
	return 0;	
}
