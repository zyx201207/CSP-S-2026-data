#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl "\n"
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define fford(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define inf 1e15
using namespace std;
const int N=2e4+505;

int c,n,m,d,q,w[N];

vector<pii> to[N+500];
void addEdge(int x,int y,int w){
	to[x].push_back({y,w});
	to[y].push_back({x,w});
}

auto cmp=[](const pii &a,const pii &b){return a.second>b.second;};
priority_queue<pii,vector<pii>,decltype(cmp)> pq(cmp);
int dis[N][500+5];
void dijkstra(int root){
	while(!pq.empty()) pq.pop();
	dis[root][root-m]=0;
	pq.push({root,0});
	while(!pq.empty()){
		int p=pq.top().first,d=pq.top().second;
		pq.pop();
		if(d>dis[p][root-m]) continue;
		for(const auto &x:to[p]){
			if(dis[p][root-m]+x.second<dis[x.first][root-m]){
				dis[x.first][root-m]=dis[p][root-m]+x.second;
				pq.push({x.first,dis[x.first][root-m]});
			}
		}
	}
}

signed main(){
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;int x,y,z;
    ffor(i,1,m) cin>>w[i];
    ffor(i,1,n){
    	cin>>x;
    	ffor(j,1,x){
    		cin>>y>>z;
    		addEdge(i+m,y,z);
		}
	}
	ffor(i,1,m+n) ffor(j,1,n) dis[i][j]=inf; 
	ffor(i,m+1,m+n){
		dijkstra(i);
	}
	ffor(i,1,q){
		int ans=inf;
		cin>>x>>y;
		ffor(j,1,n){
			ans=min(ans,dis[x][j]+dis[y][j]);
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

