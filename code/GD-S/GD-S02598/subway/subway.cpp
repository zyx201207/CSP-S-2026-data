#include<bits/stdc++.h>
using namespace std;
int c,n,l,r,m,d,q,x,y;
long long a[500005],w[500005],u,v,k,ans;
vector<vector<long long> > g(2600,vector<long long>(2600,2e18));
vector<int> t[2600];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int o=1;o<=m;o++){
		cin>>w[o];
	}for(int o=1;o<=n;o++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>u;
			t[v].push_back(o);
			g[v][m+o]=u;
			g[m+o][v]=u;
		}
	}
	for(int o=1;o<=m;o++){
		for(auto j:t[o]){
			for(auto b:t[o]){
				if(j!=b){
					g[m+j][m+b]=min(g[m+j][m+b],g[m+j][o]+g[m+b][o]);
					g[m+b][m+j]=g[m+j][m+b];
				}
			}
		}
	}
	for(int o=1;o<=n;o++){
		for(int j=1;j<=n;j++){
			for(int b=1;b<=n;b++){
				if(o!=j&&j!=b){
					g[m+j][m+b]=min(g[m+j][m+b],g[m+j][m+o]+g[m+b][m+o]);
					g[m+b][m+j]=g[m+j][m+b];
				}
			}
		}
	}
//	for(int j=1;j<=n;j++){
//			for(int b=1;b<=n;b++){
////					cout<<g[m+j][m+b]<<' ';
//				
//			}cout<<'\n';
//		}
	for(int o=1;o<=q;o++){
		cin>>x>>y;
		ans=2e18+3;
		for(auto j:t[x]){
			for(auto b:t[y]){
				if(j!=b){
					ans=min(ans,g[m+j][m+b]+g[x][m+j]+g[y][m+b]);
				}else if(j==b){
					ans=min(g[x][m+j]+g[y][m+b],ans);//cout<<j<<' '<<g[x][m+j]<<' '<<g[y][m+j]<<'\n';
				}
//				cout<<ans<<' ';
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
