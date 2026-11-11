#include<bits/stdc++.h>
#define ll long long
#define no ios::sync_with_stdio(0);
#define TLE cin.tie(0),cout.tie(0);
using namespace std;
const ll N=2e5+5;
ll n,m,a[N],ans=0,maxx=0,sum=(1<<30)-1,s1[N],s2[N];
bool A=true,B=true;
inline void dfs(ll now,ll sum,ll cnt){
	if(now==n)
	{
		if(cnt!=m)return;
		ans=max(ans,sum);
		return;
	}
	dfs(now+1,sum,cnt);
	dfs(now+1,sum&a[now+1],cnt+1);
}
void solve(){
	cin>>n>>m,s1[0]=(1<<30)-1,s2[n+1]=(1<<30)-1;
	for(ll i=1;i<=n;i++)cin>>a[i],maxx=max(maxx,a[i]),sum&=a[i],s1[i]=a[i]&s1[i-1];
	for(ll i=n;i>=1;i--)s2[i]=a[i]&s2[i+1];
	for(ll i=1;i<=n;i++)
	{
		if(a[i]!=i-1)B=false;
		ll cnt=30;
		for(ll i=0;i<=30;i++)if(a[i]!=(1<<i)-1)cnt--;
		A&=cnt;
	}
	if(n<=20)dfs(0,(1<<30)-1,0),cout<<ans,exit(0);
	if(n<=2000)
	{
		if(m==1)cout<<maxx,exit(0);
		if(m==2)
		{
			for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)if(i!=j)ans=max(ans,a[i]&a[j]);
			cout<<ans,exit(0);
		}
		if(m==n)cout<<sum,exit(0);
	}
	if(m==n-1)
	{
		for(ll i=1;i<=n;i++)ans=max(ans,s1[i-1]&s2[i+1]);
		cout<<ans,exit(0);
	}
	if(A)sort(a+1,a+n+1),cout<<a[n-m+1],exit(0);
	if(B)cout<<s2[n-m+1],exit(0);
	for(ll i=maxx;i>=0;i--)
	{
		ll cnt=0;
		for(ll j=1;j<=n;j++)if((a[j]&i)==i)cnt++;
		if(cnt>=m)cout<<i,exit(0);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	no TLE
	ll _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
