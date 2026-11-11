#include <bits/stdc++.h>
using namespace std;
const int N=5e5+3;
long long n,m,a[N],c[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		c[i]=c[i-1]+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		long long cnt,co=0,l=1,r=i,mid=(l+r)/2,kk=1;
		while(l<=r)
		{
			cnt=i-mid+1;
			long long co=cnt*a[i]-c[i]+c[mid-1];
			if(co<=m)
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
			kk=i-mid+1;
			mid=(l+r)/2;
		}
		ans=max(ans,kk);
	}
	cout<<ans;
	return 0;
}
