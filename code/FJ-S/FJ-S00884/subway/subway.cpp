#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

namespace lyh{
	
	#define int long long
	
	struct eg{
		int x,y;
		bool operator<(eg ot)const{
			return y > ot.y;
		}
	};
	
	const int N = 666666,M = 666,INF = 1e18;
	int c,n,m,d,q,w[N],dist[M][M];
	vector<eg> g[N],qs;
	
	void inlyh(){
		int k,x,y;
		cin>>c>>n>>m>>d>>q;
		for(int i = 1;i <= m;i++) cin>>w[i];
		for(int i = 1;i <= n;i++){
			cin>>k;
			while(k--){
				cin>>x>>y;
				g[x].push_back({i,y});
			}
		}
		return;
	}
	
	void build(){
		
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(i != j) dist[i][j] = INF;
		
		for(int p = 1;p <= m;p++){
			for(eg ii : g[p]){
				int i = ii.x,j = ii.y;
				for(eg jj : g[p]){
					int x = jj.x,y = jj.y;
					dist[i][x] = min(dist[i][x],j + y);
				}
			}
		}
		
		for(int k = 1;k <= n;k++) for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
		
		return;
	}
	
	void answer(){
		int x,y,s;
		while(q--){
			s = INF;
			cin>>x>>y;
			for(eg ii : g[x]){
				int i = ii.x,j = ii.y;
				for(eg jj : g[y]){
					int l = jj.x,r = jj.y;
					s = min(s,dist[i][l] + j + r);
				}
			}
			cout<<(w[x] + w[y] + s)<<'\n';
		}
		return;
	} 
	
	void solyh(){
		build();
		answer();
		return;
	}

	void lyh(){
		inlyh();
		solyh();
		return;
	}
	
	void fre(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		return;
	}
	
	#undef int
	
}

int main(){
	lyh::fre();
	lyh::lyh();
	return 0;
}
