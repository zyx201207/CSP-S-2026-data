#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M=500005;
const int N=505;

int c,n,m,d,q;

struct Station{
	int lin,t;
};

vector<Station> l[M];

int w[M];
int cnt[N];
int t[N];

struct Node{
	int v,w;
};

vector<Node> e[N];
int D[N][N];

struct dnode{
	int dis,u;
	bool operator >(const dnode &rhs) const{
		return dis>rhs.dis;
	}
};

void dijkstra(int s){
	priority_queue<dnode,vector<dnode>,greater<dnode> > pq;
	D[s][s]=0;
	pq.push((dnode){0,s});
	while(!pq.empty()){
		dnode ut=pq.top();pq.pop();
		for(auto ve:e[ut.u]){
			int vt=ve.v,wt=ve.w;
			if(D[s][vt]>D[s][ut.u]+wt){
				D[s][vt]=D[s][ut.u]+wt;
				pq.push((dnode){D[s][vt],vt});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];j++){
			int a,t;cin>>a>>t;
			l[a].push_back((Station){i,t});
		}
	}
	
	for(int i=1;i<=m;i++){
		if(l[i].size()>1){
			for(int y=0;y<l[i].size();y++){
				for(int z=y+1;z<l[i].size();z++){
					int dist=l[i][y].t+l[i][z].t;
					int ly=l[i][y].lin,lz=l[i][z].lin;
					e[ly].push_back((Node){lz,dist});
					e[lz].push_back((Node){ly,dist});
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) D[i][j]=1e18;
	}
	
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		int ans=1e18;
		for(int j=0;j<l[x].size();j++){
			for(int k=0;k<l[y].size();k++){
				int lj=l[x][j].lin,lk=l[y][k].lin;
				int dd=w[x]+l[x][j].t+D[lj][lk]+l[y][k].t+w[y];
				ans=min(ans,dd);
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
