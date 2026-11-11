#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int n,m;
bool check(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x)sum+=x-a[i];
	}
	if(sum<=m)return 1;
	else return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int l=1e12,r=-1e12,ans=0,fin=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l=min(a[i],l);
		r=max(a[i],r);
	}
	sort(a+1,a+n+1);
	while(l<=r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid+1,fin=mid;
		else r=mid-1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=fin)ans++;
	}	
	cout<<ans;
	return 0;
}