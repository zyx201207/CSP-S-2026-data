#include<bits/stdc++.h>
using namespace std;
long long n,m;
int r=0,l=INT_MAX;
int a[500005];
int ch(int x,int zu=0,int k=0)
{
	for(int i=1;i<=n;i++)
	{
		long long j=a[i]-x;
		if(j<=0)
		{
			zu+=j;
			k++;
		}  
	}
	return k;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		r=max(r,a[i]);
		l=min(l,a[i]);
	 }
	 if(r>10000)
	 {
	 	sort(a+1,a+n+1);
	 	long long b=a[2]-a[1];
	 	int s=1;
	 	for(int i=1;i<=n;i++)
	 	{
	 		m-=s;
	 		s+=i;
	 		if(m<=0)
	 		{
			 	cout<<i;
			 	return 0;	
			}
		 }
	}
	int ans=0;
	while(r>l)
	{
		int mid=(r+l+1)/2;
		if(ch(mid)>=ans)
		{
			ans=ch(mid);
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
 } 
