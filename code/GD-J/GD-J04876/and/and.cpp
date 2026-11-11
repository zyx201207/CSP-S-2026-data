#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,sum=-1e9;
ll a[200005];
ll w[200001][31];
ll g[200001];
bool v[200005];
void dfs(ll x,ll f){
	if(x==m){
		ll p=0;
		for(ll i=1;i<=n;i++){
			if(v[i]){
				if(!p) p=a[i];
				else p=p&a[i];
			}
		}
		sum=max(sum,p);
		return ;
	}
	for(ll i=f;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(x+1,f+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		ll maxx=-1e9;
		for(ll i=1;i<=n;i++) maxx=max(maxx,a[i]);
		cout<<maxx;
		return 0;
	}if(n==m){
		ll sum=1;
		for(ll i=1;i<=n;i++){
			if(i==1) sum=a[i];
			else sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}if(m==2){
		ll maxx=-1e9;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}if(m==n-1){
		ll maxx=-1e9;
		for(ll i=1;i<=n;i++){
			ll x=0;
			for(ll j=1;j<=n;j++){
				if(i==j) continue;
				if(!x) x=a[i];
				else x=x&a[j];
			}
			maxx=max(maxx,x);
		}
		cout<<maxx;
		return 0;
	}if(n<=20){
		dfs(0,1);
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		ll t=a[i];
		while(t){
			w[i][++g[i]]=t%2;
			t=t/2;
		}
	}
	for(ll i=30;i>=1;i--){
		ll shu=0;
		for(ll j=n;j>=1;j--){
			if(w[i][j]) shu++;
		}
		if(shu>=m){
			ll u=0,ans=1;
			for(ll j=n;j>=1&&ans<=m;j--){
				if(w[i][j]&&!u){
					u=a[j];
					ans++; 
				}
				else{
					u=u&a[j];
					ans++;
				}
			}
			cout<<u;
			return 0;
		}
	}
	return 0;
}
