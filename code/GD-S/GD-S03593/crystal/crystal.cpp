#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];long long n,m;
long long b[N];
bool cheek(long long x)
{
	if(x==1) return 1;
	for(int i=x;i<=n;i++)
	{
		if(a[i]*(x-1)-(b[i-1]-b[i-x])<=m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<r)
	{
		long long mid=(l+r)/2;
		if(cheek(mid))
		{
			if(l==r-1&&mid==l)break;
			l=mid;
		}
		else 
		{
			r=mid-1;
		}
	}
	if(r==l) cout<<l;
	else if(cheek(r)) cout<<r;
	else cout<<l;
	return 0;
}
