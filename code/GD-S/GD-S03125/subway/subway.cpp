#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+5,M=5e5+5;
vector<pair<int,ll> > e[M],to[N];
ll d[N][N],v[M];
int c,n,m,dd,q;
void solve(){
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++) cin>>v[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			cin>>a>>t;
			to[i].push_back({a,t});
			e[a].push_back({i,t});
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++){
		d[i][i]=0;
		for(auto x : to[i]){
			int st=x.first;
			ll w=x.second;
			for(auto y : e[st]){
				int j=y.first;
				ll w2=y.second;
				d[i][j]=d[j][i]=min(d[i][j],w+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=d[0][0];
		for(auto u : e[x]){
			for(auto v : e[y]){
				int s1=u.first,s2=v.first;
				ll w1=u.second,w2=v.second;
				ans=min(ans,d[s1][s2]+w1+w2);
			} 
		}
		cout<<ans+v[x]+v[y]<<'\n';
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) solve();
	return 0;
}
