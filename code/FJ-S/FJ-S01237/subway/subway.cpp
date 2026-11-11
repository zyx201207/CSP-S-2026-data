#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int M=5e5+5,N=505;
const ll inf=1ll<<60;
ll c,n,m,d,q,W[M],k[N],dis[N][N],ans;
vector<int> a[N],t[N];
vector<pii> g[M];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+5,0);
		t[i].resize(k[i]+5,0);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int u=1;u<=n;u++){
		for(int j=1;j<=k[u];j++){
			for(pii &p:g[a[u][j]]){
				ll v=p.first,w=p.second;
				dis[u][v]=min(dis[u][v],t[u][j]+w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=inf;
		for(pii &p1:g[x]){
			ll u=p1.first,w1=p1.second;
			for(pii &p2:g[y]){
				ll v=p2.first,w2=p2.second;
				ans=min(ans,w1+w2+dis[u][v]);
			}
		}
		ans+=W[x]+W[y];
		cout<<ans<<'\n';
	}
	return 0;
}