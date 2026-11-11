#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N=1e6+5;
int a[N],sum[N],v[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]*i-sum[i]<=m)
		{
			ans=max(ans,i);
		}
		else
		{
			int l=0,r=n+1,k=a[i]*i-sum[i];
			while(l+1<r)
			{
				int mid=(l+r)>>1;
				if(k-(a[i]*mid-sum[mid])<=m) r=mid;
				else l=mid;
			}
			ans=max(ans,i-r);
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
