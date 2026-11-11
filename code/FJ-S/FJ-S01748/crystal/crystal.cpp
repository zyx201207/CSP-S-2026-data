#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long b[500010];
bool check(long long mid,long long i)
{
	long long x=b[i]-b[mid-1]-(a[n]-a[i])*(i-mid+1);
	return x<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);         //¼ÇµÃÉ¾×¢ÊÍ 
	cin>>n>>m;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long flag=0,k=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=k)
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		long long d=a[2]-a[1];
		m/=d;
		long long x=sqrt(m*2);
		if((x+1)*(x+2)/2<=m)cout<<x+2;
		else if(x*(x+1)/2<=m)cout<<x+1;
		else cout<<x;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[n]-a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long l=1,r=i;
		while(l<r)
		{
			long long mid=(l+r)/2;
			if(check(mid,i))r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}





















//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
//X X X X X X X X X X X X X X X X 
