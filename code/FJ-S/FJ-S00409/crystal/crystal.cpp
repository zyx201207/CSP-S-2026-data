#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long diff[500005];
long long ans;
bool check(int len)
{
	long long d=1e18;
	for(int i=len;i<=n;i++)
	{
		long long cnt=0;
		for(int j=0;j<len-1;j++)
		{
			cnt+=diff[i-j]*(len-j-1);
		}
		//cout<<cnt<<endl;
		d=min(d,cnt);
	}
	return d<=m;
}
int main(){
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
		diff[i]=a[i]-a[i-1];
	}
	long long l=1,r=n;
	long long ans=1;
	while(l<=r)
	{
		long long mid=l+(r-l)/2;
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
