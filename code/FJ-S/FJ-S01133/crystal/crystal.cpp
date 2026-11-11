#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],ans=1;
long long work(long long p)
{
	
	long long l=1,r=p;
	while(l<r)
	{
		long long mid=(r-l)/2+l,s=(a[p]-a[p-1])*(p-mid+1);
		long long js=s-(a[p]-a[mid-1]);
	//	cout<<l<<" "<<r<<" "<<js<<endl;
		if(js>=m) l=mid+1;
		else r=mid;
	}
	for(long long i=max(1ll,r-2);i<=min(r+2,p);i++)
	{
		if((a[p]-a[p-1])*(p-i+1)-(a[p]-a[i-1])<=m)
		{
			return p-i+1;
		}
	}
	return p-r+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	//	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		a[i]=a[i-1]+a[i];
		ans=max(ans,work(i));
	}
	printf("%lld",ans);
	return 0;
}/*
5 5
1 2 4 8 9
*/
