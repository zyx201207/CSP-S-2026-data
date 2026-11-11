#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans,l,r,mid;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		l=1,r=i;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(a[i]*(i-mid)-(b[i-1]-b[mid-1])>m)
				l=mid+1;
			else
				r=mid-1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	
	return 0;
}


