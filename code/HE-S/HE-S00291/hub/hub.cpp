#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e6+100;
ll c,t,n,k,u,v,ans,s[1090][1090],maxx=-1;

void solve(){
	maxx=-1;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			s[i][j]=0;
		}
	}
	for(ll i=1;i<=n-1;i++){
		cin>>u>>v;
		s[u][v]=1;
		s[v][u]=1;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(s[i][j]==0){
				s[i][j]=9999999999;
			}
			if(i==j){
				s[i][j]=0;
			}
		}
	}
	for(ll l=1;l<=n;l++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				s[i][j]=min(s[i][j],s[i][l]+s[j][l]);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			maxx=max(maxx,s[i][j]);
		}
	}
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	ans=maxx/2;
	cout<<ans<<'\n';
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
