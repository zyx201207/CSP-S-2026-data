//GZ_S00174 北京师范大学贵阳附属中学 李培源
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,c,d,q;
long long h[505][505],w[505],f[505][N];
vector<int >g[505];
vector<int> r[N];
int sz;
void dfs(int u){
	for(auto i:r[u]){
//		cout<<'^'<<i;
		for(auto v:g[i]){
//			cout<<'#'<<h[sz][u]+f[i][v];
			if(h[sz][v]>h[sz][u]+f[i][v]+f[i][u]){
//				cout<<'*';
				h[sz][v]=h[sz][u]+f[i][v]+f[i][u];
				dfs(v);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(h,0x3f,sizeof h);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			r[a].push_back(i);
			g[i].push_back(a);
			f[i][a]=t;
		}
	}
	for(int i=1;i<=m;i++){
		sz=i;
		h[i][i]=0;
		dfs(i);
//		cout<<h[i][i]<<endl;
		
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<setw(3)<<h[i][j];
//		}
//		cout<<endl;
//	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<w[u]+h[u][v]+w[v]<<"\n";
	}
	return 0;	
}
