#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum[500005],s[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]),sum[i]=sum[i-1]+a[i];
//	for(int i=1;i<=n;i++)
//		cout<<s[i]<<" ";
	for(ll i=n;i>=1;i--)
	{
		if(s[i]>m)
		{
			int l=1,r=i,num=s[i]-m;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(mid*a[i]-sum[mid]<num)
					l=mid+1;
				else
					r=mid;
			}
			if(l*s[l]==num)
				ans=max(ans,i-l+1);
			else
				ans=max(ans,i-l);
		}
		else
		{
			ans=max(ans,i);
			break;
		}
	}
	cout<<ans;	
	return 0;
} 
