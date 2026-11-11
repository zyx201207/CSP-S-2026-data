#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
ll ans=0;
void dfs(ll k,ll cnt,ll sum){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(k>n+1) return;
	if(n-k+1+cnt<m) return;
	if(sum==0){
		dfs(k+1,cnt+1,a[k]);
		dfs(k+1,cnt,0);
	}
	else{
		dfs(k+1,cnt+1,sum&a[k]);
		dfs(k+1,cnt,sum);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)
		ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
		ans&=a[i];
	}
	if(n>2000){
		sort(a+1,a+n+1,greater<ll>());
		cout<<a[m];
		return 0;
	}
}
