#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[500010];
ll pre[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	a[0]=-1e18;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			
			if(a[i]*mid-(pre[i-1]-pre[i-mid-1])<=m)
			{
				l=mid+1;
			}
			else r=mid;
		}
		ans=max(ans,r);
	}
	cout<<ans;
	return 0;
}

