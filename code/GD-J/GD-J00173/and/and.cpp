#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[200005],t,ans;
bool f[200005];
ll dfs(ll k,ll len,ll asa)
{
	
	if(len==m)
	{
		ans=max(ans,asa);	
	}
	if(n-k+1<m-len) return 0;
	for(int i=k;i<=n;i++)
	{
		dfs(i+1,len+1,asa&a[i]);
		
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
	}
	if(n==m)
	{
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	ll t=1;
	for(int i=1;i<=30;i++) t*=2; 
	dfs(1ll,0ll,t-1);
	cout<<ans;
	
	return 0; 
}
