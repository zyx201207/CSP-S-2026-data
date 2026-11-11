#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n;
long long m;
long long ans=0;
bool cheak(long long mid)
{
	long long sum=0;
	long long cnt=0;
	for(int i=mid;i>=1;i--)
	{
		sum+=(a[mid]-a[i]);
		if(sum>m)
		{
			ans=max(cnt,ans);
			return false;
		 } 
		cnt++;
	}
	ans=max(cnt,ans);
	return true;
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
	sort(a+1,a+1+n);
	long long l=1,r=n;

	while(l+1<r)
	{
		long long mid=(l+r)/2;
		
		if(cheak(mid)==true)
		{
			l=mid;

		}
		else
		{
			r=mid;
		} 
	}
	r=n;
	long long last=l;
	while(l+1<r)
	{
		cheak(r);
		cheak(l);
		long long mid=(l+r)/2;

//		cout<<last<<" ";
		if(cheak(mid)==true||ans>=last)
		{
			last=ans;
			l=mid;
		}
		else
		{
			last=ans;
			r=mid;
		} 
	
	}
	cheak(l);
	cout<<ans;
	return 0;
 } 
