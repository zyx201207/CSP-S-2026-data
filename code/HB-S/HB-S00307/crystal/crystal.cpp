#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,asn;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m)r=mid-1,asn=mid;
			else l=mid+1;
		}
		ans=max(ans,i-asn+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
2 1 2 4 8 9
5 8
-3 -1 2 2 7
*/
