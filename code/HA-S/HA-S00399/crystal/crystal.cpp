#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],sum,ans=-9999,q[500010];
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
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if((m-((i-mid)*a[i])+(q[i-1]-q[mid-1]))>=0)
			{
				ans=max(ans,(long long)(i-mid+1));
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
