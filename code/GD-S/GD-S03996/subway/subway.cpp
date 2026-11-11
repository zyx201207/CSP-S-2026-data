#include<bits/stdc++.h>
using namespace std;
const int N=505,M=125100;
using ll=long long;
struct node{
	ll line,go;
};
ll c,n,m,d,q;
ll w[M];
vector<ll> a[N],t[N];
vector<node> chan[M];
ll mp[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			chan[x].push_back({i,y});
			if(chan[x].size()>1){
				for(auto l:chan[x]){
					mp[i][l.line]=min(mp[i][l.line],y+l.go);
					mp[l.line][i]=min(mp[l.line][i],y+l.go);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
			}
		}
	}
	while(q--){
		ll u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(node i:chan[u]){
			for(node j:chan[v]){
				if(i.line!=j.line)ans=min(ans,mp[i.line][j.line]+i.go+j.go);
				else ans=min(ans,i.go+j.go);
			}
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
} 
