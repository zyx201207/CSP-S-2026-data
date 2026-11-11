#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,a[M];
long long f[N][N];
vector<pair<int,int> >e[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int k,u,v,w;
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>w;
			e[u].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto g1:e[i]){
			u=g1.first;
			for(auto g2:e[i]){
				v=g2.first;
				f[u][v]=f[v][u]=min(f[u][v],0ll+g1.second+g2.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}long long ans=0;
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		ans=0x3f3f3f3f3f3f3f3f;
		for(auto g1:e[u]){
			for(auto g2:e[v]){
				ans=min(ans,f[g1.first][g2.first]+g1.second+g2.second);
			}
		}
		cout<<ans+a[u]+a[v]<<'\n';
	}
}
