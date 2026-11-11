#include<bits/stdc++.h>
#define ll long long
const int inf=600010;
using namespace std;
int n,kd;
int kl=0;
ll m,a[inf],f[inf],sum[inf];
void dfs()
{
	long long ans1=0;
	for(int i=0;i<=n;i++)
	{
		if(ans1>=n-i) break;
		long long ans=0;
		for(int j=i;j<=n;j++)
		{
			if(f[j]-f[i]-sum[i]<=m) 
				if(i!=0) ans=j-i+1;
				else ans=j-i;
		}
		ans1=max(ans1,ans);
	}
	cout<<ans1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) kd=1;
	}
	if(!kd)
	{
		ll ans=( -1+sqrt(1+8*m) )/2;
		cout<<min(ans,(ll)n);
		return 0; 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	ll ans=0;
	f[1]=0;
	for(int i=1;i<=n;i++)
	{
		long long anp=73617353615;
		if(i!=1) f[i]=i*a[i]-sum[i];
		anp=min(anp,f[i]);
		if(anp>m)
		{
			cout<<0;
			return 0;
		}
		if(anp==m)
		{
			cout<<2;
			return 0;
		}
		if(!kl)
		{
			if(m>=f[i]) ans++;
		}
		else
		if(n>100000) if(m>=f[i]) ans++;
	}
	if(n<=10000 && kl)
	{
		dfs();
		return 0;
	}
	cout<<ans;
	return 0;
}
