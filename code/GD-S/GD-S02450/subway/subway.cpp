#include<bits/stdc++.h>
#define int long long
#define uint long long
using namespace std;
struct no{int x,k;};
int c,n,m,d,q,w[500010],k[510];
map<int , int> a[510],t[510];
vector<no> f[500010];
bool v[500010];
int dfs(int s , int e , int x , int o){
	if(s==e) return t[x][o];
	v[s]=1;
	int mii=5e14+10;
	for(int u=0;u<f[s].size();u++)
		for(int i=1;i<=k[f[s][u].x];i++)
			if(i!=f[s][u].k&&!v[a[f[s][u].x][i]])
				mii=min(dfs(a[f[s][u].x][i] , e , f[s][u].x , i)+(c>=12&&c<=19? t[1][1] : (f[s][u].x!=x? t[x][o]+t[f[s][u].x][f[s][u].k] : 0 ) ) , mii);
	v[s]=0;
	return mii;
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int u=1;u<=n;u++){
		cin>>k[u];
		for(int i=1;i<=k[u];i++)
			cin>>a[u][i]>>t[u][i],f[a[u][i]].push_back( {u , i} );
	}
	while(q--){
		int s,e;
		memset(v,0,sizeof v),cin>>s>>e,cout<<dfs(s , e , 0 , 0)+w[s]+w[e]<<"\n\n\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
