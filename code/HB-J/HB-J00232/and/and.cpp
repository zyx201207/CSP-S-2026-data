#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,a[200005],ans,maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){cin>>a[i];maxn=max(maxn,a[i]);}
	if(m==n)
	{
		ans=a[1]&a[2];
		for(ll i=3;i<n;i++)ans=a[i]&ans;
		cout<<ans;
	}
	else if(m==1)cout<<maxn;
	else 
	{
		sort(a+1,a+n+1);
		ans=a[n]&a[n-1];
		for(ll i=n-2;i>1;i--)ans=a[i]&ans;
		cout<<ans;
	}
	return 0;
}

