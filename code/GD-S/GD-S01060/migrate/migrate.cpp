#include<bits/stdc++.h>
using namespace std;
using ll=long long;
queue<ll> q;
ll n,d,a[2000001];
void dfs(ll x,ll v,ll cnt){
	if(x==v){
		if(!q.empty()){
			if(cnt<q.front()){
				while(!q.empty())q.pop();
				q.push(cnt);
			}
			else if(cnt==q.front())q.push(cnt);
		}
		else q.push(cnt);
	}
	for(ll i=1;a[x+i]-a[x]<=d&&x+i<=v;i++)dfs(x+i,v,cnt+1);
	return ;
}
void solve(){
	ll ans=0;
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll u=1;u<n-2;u++){
		for(ll v=u+3;v<=n;v++){
			dfs(u,v,0);
			if(q.size()==2)ans++;
			while(!q.empty())q.pop();
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,_;
	cin>>c>>_;
	while(_--)solve();
	return 0;
}
