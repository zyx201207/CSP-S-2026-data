#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m,l,r,mid;
int sum[500012],a[500012];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(a[i]*x-(sum[i]-sum[i-x])<=m)return true;
	}
	return false; 
}
signed main()
{	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	l=0,r=n;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
} 

