#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500050],c[500050],s[500050];
bool chk(int x)
{
	for(int i=x;i<=n;i++)
	{
		ll nw=s[i]-s[i-x]-c[i]*x;
		if(nw<=m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		c[i]=a[n]-a[i];
		s[i]=s[i-1]+c[i];
	}
	int l=0,r=n+1,ans=0; 
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(chk(mid)==1)
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid;
	}
	cout<<ans;
	return 0;
}
