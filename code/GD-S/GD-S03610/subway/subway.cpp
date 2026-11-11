#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w[N]{};
long long g[505][505]{};
vector<pair<int,int>>station[N]{};//first表示第几号线，second表示换乘时间 
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			station[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) g[i][j]=1e13+5;
			else g[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<station[i].size();j++){
			for(int k=0;k<station[i].size();k++){
				if(j==k) continue;
				int fir=station[i][j].first,sec=station[i][k].first;
				long long time=station[i][j].second+station[i][k].second;
				g[fir][sec]=g[sec][fir]=min(g[fir][sec],time);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ti=1e13+5;
		for(int i=0;i<station[x].size();i++){
			for(int j=0;j<station[y].size();j++){
				int fir=station[x][i].first;
				int sec=station[y][j].first;
				long long time=station[x][i].second+station[y][j].second;
				ti=min(ti,g[fir][sec]+time);
			}
		}
		cout<<ti+w[x]+w[y]<<'\n';
	}
	return 0;
}
