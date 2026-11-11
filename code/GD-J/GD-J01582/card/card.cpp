#include<bits/stdc++.h>
#define ll long long
#define no ios::sync_with_stdio(0);
#define TLE cin.tie(0),cout.tie(0);
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],x[N],ans[N],pos[N];
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i],x[a[i]]=i;
	if(n<=500&&m<=200)
	{
		for(ll i=1;i<=n;i++)
		{
			memset(pos,0,sizeof pos);
			for(ll j=i;j<=n;j++)
			{
				if(pos[a[j]])for(ll k=1;k<=m;k++)if(pos[k]>=pos[a[j]]&&k!=a[j])pos[k]=0;
				pos[a[j]]=j;
			}
			for(ll j=1;j<=m;j++)if(pos[j])ans[j]++;
		}
		for(ll i=1;i<=m;i++)cout<<ans[i]<<' ';
		exit(0);
	}
	for(ll i=1;i<=m;i++)cout<<x[i]<<' ';
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	no TLE
	ll _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
