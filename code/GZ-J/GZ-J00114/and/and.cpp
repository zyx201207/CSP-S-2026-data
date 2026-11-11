//GZ-J00114 Õı’˝≈Ì 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[2005][2005];
ll a[200005];
bool pd(ll x)
{
	ll j=32;
	while(j--)
		if(x==(1LL<<j)-1)
			return 1;
	return 0;
}
bool flag[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m,maxx=0;
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],maxx=max(maxx,a[i]);
		if(!pd(a[i]))
			flag=0;
	}
	if(flag)
	{
		sort(a+1,a+n+1);
		ll ans=a[n];
		for(int i=n-1;i>n-m;i--)
		ans&=a[i];
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1)
	{
		cout<<maxx<<'\n';
		return 0;
	}
	if(m==n)
	{
		ll andd=a[1];
		for(int i=2;i<=n;i++)
		andd&=a[i];
		cout<<andd<<'\n';
		return 0;
	}
	for(int i=0;i<=n;i++)
		f[i][0]=(1<<32)-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=a[i];
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=max(f[i][j],(f[i-1][j-1]&a[i]));
	cout<<f[n][m]<<'\n';
	return 0;
}
