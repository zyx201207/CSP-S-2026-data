#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=5e5+505;
const int INF=1e15;
int c,n,m,d,q,k,a,t,x,y,sumk,mn;
int w[N],ll[N][N];
vector<pair<int,int> > g[M];
int dis[1005][1005],sy[M];
bool st[M];
struct node{
	int u,dist;
	bool operator<(const node &W)const{
		return dist>W.dist;
	}
};
void dij(int bg){
	priority_queue<node> qu;
//	qu.clear();
	for(int i=1;i<=m+n;++i) dis[bg][i]=INF,st[i]=0;
	dis[bg][bg]=0;
	qu.push({bg,0});
	while(!qu.empty()){
		int uu=qu.top().u;
		qu.pop();
		if(st[uu]) continue;
		st[uu]=1;
		for(int i=0;i<(int)g[uu].size();++i){
			int vv=g[uu][i].first;
			int ww=g[uu][i].second;
			if(dis[bg][vv]>dis[bg][uu]+ww){
//				pre[vv]=uu;
				dis[bg][vv]=dis[bg][uu]+ww;
				qu.push({vv,dis[bg][vv]});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
		sy[i]=0;
	}
	memset(ll,0x3f,sizeof(ll));
	for(int i=1;i<=n;++i){
		cin>>k;
		sumk+=k;
		for(int j=1;j<=k;++j){
			cin>>a>>t;
			sy[a]+=i;
			g[i+m].push_back({a,t});
			g[a].push_back({i+m,t});
			ll[i+m][a]=t;
			ll[a][i+m]=ll[i+m][a];
		}
	}
	if(sumk<=400){
		for(int zj=1;zj<=m+n;++zj){
			for(int i=1;i<=m+n;++i){
				for(int j=1;j<=m+n;++j){
					ll[i][j]=min(ll[i][j],ll[i][zj]+ll[zj][j]);
				}
			}
		}
	}
	if(n==2){
		mn=INF;
		for(int i=1;i<=m;++i){
			if(g[i].size()==2)mn=min(mn,g[i][0].second+g[i][1].second);
		}
	}
	while(q--){
		cin>>x>>y;
		if(sumk<=400) cout<<w[x]+w[y]+ll[x][y]<<"\n";
		else if(n==2){
			if(sy[x]==3&&sy[y]==3) cout<<w[x]+w[y]+min({g[x][0].second+g[y][0].second,g[x][1].second+g[y][1].second,g[x][1].second+g[y][0].second+mn,g[x][0].second+g[y][1].second+mn})<<"\n";
			else if(sy[x]==3&&sy[y]==2) cout<<w[x]+w[y]+g[y][0].second+min(g[x][0].second+mn,g[x][1].second)<<"\n";
			else if(sy[x]==3&&sy[y]==1) cout<<w[x]+w[y]+g[y][0].second+min(g[x][1].second+mn,g[x][0].second)<<"\n";
			else if(sy[x]==2&&sy[y]==3) cout<<w[x]+w[y]+g[x][0].second+min(g[y][0].second+mn,g[y][1].second)<<"\n";
			else if(sy[x]==1&&sy[y]==3) cout<<w[x]+w[y]+g[x][0].second+min(g[y][1].second+mn,g[y][0].second)<<"\n";
			
			else cout<<w[x]+w[y]+g[x][0].second+g[y][0].second+mn*(g[x][0].first!=g[y][0].first)<<"\n";
//			cout<<w[x]<<" "<<w[y]<<" "<<g[x][0].second<<" "<<g[y][0].second<<" "<<mn<<" "<<g[x][0].first<<" "<<g[y][0].first<<"\n";;
		}
		else{
			if(dis[x][y]==0) dij(x);
			cout<<w[x]+w[y]+dis[x][y]<<"\n";
//			int now=y;
//			while(now!=x){
//				cout<<now<<" ";
//				now=pre[now];
//			}
//			cout<<"\n";
		}
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3