#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,ans;
vector<ll>l[1000010];
ll f[1000010];
void dfs(ll p,ll las=1){
//	cout<<p<<" "<<las<<'\n';
	for(auto&i:l[p]){
		if(i!=las)dfs(i,p);
	}
	if(las!=p){
		ans=max(ans,f[p]+f[las]);
		f[las]=max(f[las],f[p]+1);
	}
}
int main(){
	freopen("hub.in" ,"r",stdin );
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)l[i]=vector<ll>();
		for(int i=1;i<n;++i){
			ll u,v;
			cin>>u>>v;
			l[u].push_back(v);
			l[v].push_back(u);
//			cout<<u<<" "<<v<<'\n';
		}
//		cout<<n<<" "<<k;
		dfs(1);
		cout<<(ans-k+1)/2<<'\n';
	}
	return 0;
} 
