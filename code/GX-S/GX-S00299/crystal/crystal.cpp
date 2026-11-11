#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],pre[N];
long long n,m,ans;
bool check(long long x)
{
	for(int i=x;i<=n;i++)
	{
		if(pre[i]-pre[i-x]-(i-x)*(a[i]-a[i-x])<=m)
			return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

