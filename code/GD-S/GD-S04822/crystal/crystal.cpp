#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],p1[500005],p2[500005];
int maxx=-1;
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
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		maxx=max(maxx,i-l+1);
	}
	cout<<maxx;
	return 0;
}
