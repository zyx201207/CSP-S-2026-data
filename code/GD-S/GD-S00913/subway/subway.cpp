#include<bits/stdc++.h>
#define int long long
#define No ios::sync_with_stdio(0);
#define TLE cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=510;
const int SM=1e3+10;
const int M=5e5+10;
void _freopen(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
int w[M];
int ans=0;
struct edge{
	int u,t;
}a[N][1001];
vector<int>g[1001];
int k[N];
int f[1001][1001];
int c,n,m,d,q;
void solve2(){
		for(int i=1;i<=n;i++){
		cin>>k[i];
		//cin>>a[i][1].u>>a[i][1].t;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j].u>>a[i][j].t;
		}
	}
	memset(f,0x3f3f3f3f3f3f3f3f,sizeof f);
	for(int i=1;i<=n;i++){
		int u=a[i][1].u,v=a[i][2].u;
		f[u][v]=min(f[u][v],a[i][1].t+a[i][2].t);
		f[v][u]=min(f[v][u],a[i][1].t+a[i][2].t);
		//cout<<u<<' '<<v<<f[u][v]<<endl;
	}
	for(int i=1;i<=m;i++){
		f[i][i]=0;
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<f[u][v]+w[u]+w[v]<<endl;
	}
} 
bool v1[M],v2[M];
int b[N];
void solve3(){
	int x=0,sx=0,sy=0;
	cin>>k[1];
	for(int j=1;j<=k[1];j++){
		int u,t;
		cin>>u>>t;v1[u]=1,b[u]=t;
	}
	cin>>k[2];
	for(int j=1;j<=k[2];j++){
		int u,t;
		cin>>u>>t;v2[u]=1,b[u]+=t;
		if(v1[u]==1) x=u,sx=b[u]-t,sy=t;
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(u==x){
			if(v1[v]==1) cout<<w[u]+w[v]+sx+b[v];
			else cout<<w[u]+w[v]+sy+b[v]<<endl;
		}else if(v==x){
			swap(u,v); 
				if(v1[v]==1) cout<<w[u]+w[v]+sx+b[v]<<endl;
			else cout<<w[u]+w[v]+sy+b[v]<<endl;
		}
		else if((v1[u]==1&&v1[v]==1)||(v2[u]==1&&v2[v]==1)){
			cout<<w[u]+w[v]+b[u]+b[v]<<endl;
			continue;
		}else{
			cout<<w[u]+w[v]+b[x]+b[u]+b[v]<<endl;
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c>=7&&c<=11) solve2();
	else if(c==20||c==21) solve3();
}
signed main(){
	No TLE
	_freopen();
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
}

