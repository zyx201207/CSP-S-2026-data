#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N(505),M(5e5+5),D(25);
const ll inf(1e18);
int n,m,d,q,k,sta;
int bel[M][D],cnt[M];
ll t[M][D];
ll dis[N][N],w[M],tim;
ll ans;
void sol(){
	int x,y; cin>>x>>y;
	ans=inf;
	for(int i(1);i<=cnt[x];++i){
		for(int j(1);j<=cnt[y];++j){
			ans=min(ans,w[x]+w[y]+t[x][i]+t[y][j]+dis[bel[x][i]][bel[y][j]]);
		}
	}cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cs; cin>>cs;
	cin>>n>>m>>d>>q;
	for(int i(1);i<=m;++i) cin>>w[i];
	for(int i(1);i<=n;++i){
		for(int j(1);j<=n;++j){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i(1);i<=n;++i){
		cin>>k;
		for(int j(1);j<=k;++j){
			cin>>sta>>tim;
			++cnt[sta];
			bel[sta][cnt[sta]]=i;
			t[sta][cnt[sta]]=tim;
		}
	}
	for(int i(1);i<=m;++i){
		for(int j(1);j<cnt[i];++j){
			for(int k(j+1);k<=cnt[i];++k){
				dis[bel[i][j]][bel[i][k]]=min(dis[bel[i][j]][bel[i][k]],t[i][j]+t[i][k]);
				dis[bel[i][k]][bel[i][j]]=min(dis[bel[i][k]][bel[i][j]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k(1);k<=n;++k)
		for(int i(1);i<=n;++i)
			for(int j(1);j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(;q;--q) sol();
	return 0;
}
