#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int INF=1e9;
const int N=5e5+10;

ll m;
ll pre[N];
ll a[N];
int n;

bool check(ll x)
{
	for(int i=x;i<=n;++i)
	{
		if(a[i]*x-(pre[i]-pre[i-x])<=m)return true;
	}
	return false;
}


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	ll l=1,r=n,mid,ans=1;
	while(l<r)
	{
		mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans<<"\n";
}

