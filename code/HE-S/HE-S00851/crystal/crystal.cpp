#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int pre[500005];
int ansmax=-1e18;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-1,mid=0,ans1=0,ans2=0;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(((a[i]*(i-mid))-(pre[i-1]-pre[mid-1]))<=m)
			{
				r=mid-1;
				ans1=r;
				ans2=i;
			}
			else
			{
				l=mid+1;
			}
		}
		ansmax=max(ansmax,ans2-ans1);
	}
	cout<<max(ansmax,1ll)<<endl;
} 
