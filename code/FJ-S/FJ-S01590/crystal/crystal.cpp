#include<bits/stdc++.h>
using namespace std;
long long d[500005],s1[500005],s2[500005],a[500005];
long long n,m;
long long s(long long i,long long x)
{
	long long l=1,r=i;
	while(l<r)
	{
		long long mid=(l+r)>>1;
//		cout<<l<<" "<<r<<" "<<mid<<" "<<i<<" "<<s2[mid]-(n-mid)*a[n]+(n-mid)*a[i]<<endl;
		if(s2[mid]-s2[i]-(i-mid)*a[n]+(i-mid)*a[i]==x)return mid;
		else if(s2[mid]-s2[i]-(i-mid)*a[n]+(i-mid)*a[i]<x)r=mid;
		else l=mid+1;
	}
	return s2[l]-s2[i]-(i-l)*a[n]+(i-l)*a[i]<x?l:l+1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=0)
	{
		long long ans=0;
		for(long long i=n;i>=1;i--)
		{
			if(ans>=i)break;
			long long cnt=0,cntt=1;
			for(long long j=i-1;j>=1;j--)
			{
				cnt+=a[i]-a[j];
	//			cout<<a[j]<<endl;
				if(cnt>m)break;
				cntt++;
			}
			ans=max(ans,cntt);
		}
		cout<<ans<<endl;
		return 0;
	}
	for(long long i=1;i<=n;i++)d[i]=a[i]-a[i-1];
	for(long long i=n-1;i>=1;i--)s1[i]=s1[i+1]+d[i+1];
	for(long long i=n-1;i>=1;i--)s2[i]=s2[i+1]+s1[i];
//	reverse(s2+1,s2+n+1);
//	for(long long i=1;i<=n;i++)cout<<s2[i]<<" ";
//	cout<<endl;                 
	long long ans=0;
	unordered_map<long long,long long> cnt;
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	for(int i=1;i<=n;i++)ans=max(ans,cnt[a[i]]);
	for(long long i=n;i>=1;i--)
	{
		if(ans>=i)break;
		long long x=s(i,m);
//		cout<<i<<" "<<x<<endl;
		ans=max(ans,i-x+1);
	}
//	cout<<s2[2]<<endl;
	cout<<ans<<endl;
	return 0; 
}
/*
14:30~15:53
T1 crystal 100/100 pts
²»ÄÑÏë°É¡£ 
*/
