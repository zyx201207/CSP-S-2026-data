#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010]={0};
int b[500010]={0};
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]+b[i-1];
	}
	int ans=0,l,r;
	for(l=0,r=1;r<=n;r++)
	{
		while(a[r]*(r-l)-b[r]+b[l]>m)l++;
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
