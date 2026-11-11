#include<bits/stdc++.h>
using namespace std;
long long n,a[1010101],sum[1091011],m;
long long val(long long pos){
	long long l=1,r=pos;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if((pos-mid+1)*a[pos]-(sum[pos]-sum[mid-1])<=m){
			r=mid-1;
		}else
		{
			l=mid+1; 
		}
	}
	return (pos-l+1);
} 
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
    {
    	sum[i]=sum[i-1]+a[i];
    	ans=max(ans,val(i));
	}
	cout<<ans; 
}
