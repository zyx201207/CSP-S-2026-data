#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],sum[N];
bool check(int x,int k)
{
	return (x-k)*a[x]-sum[x-1]+sum[k-1]<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
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
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(int i=n;i>=2;i--)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(check(i,mid))
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
