#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long f[500005];
bool check(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		if((long long)(a[i+x-1]*x-(f[i+x-1]-f[i-1]))<=m)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		f[i]=(long long)(a[i]+f[i-1]);
	}
	int l=1,r=n;
	int mid=0;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid;
		}
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
