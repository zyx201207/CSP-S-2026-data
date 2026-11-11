#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,f,sum[500005],ans;
long long check(long long x)
{
	long long l=1,r=x,answ=n,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[x]*(x-mid+1)-sum[x]+sum[mid-1]>m) l=mid+1;
		else r=mid-1,answ=mid;
	}
	return x-answ+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			f=1;
		}
	}
	if(f) sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		ans=max(ans,check(i));
	}
	cout<<ans<<"\n";
	return 0;
} 
