#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=505;
const int M=500005;
//n条线路，m个地铁站
struct cross{
	int line;
	int stat;
	int time;
	bool operator == (const cross &oth)const{
		return line==oth.line&&stat==oth.stat;
	}
};
vector<cross> sta[M]; 
int G[N][N];
//int dis[N][N];
int c,n,m,d,q;
int w[M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			sta[a].push_back({i,a,t});
		}
	}
	memset(G,0x3f,sizeof G);
	for(int i=1;i<=m;i++){
		for(cross u : sta[i]){
			for(cross v : sta[i]){
				if(u==v) continue;
				G[u.line][v.line]=min(G[u.line][v.line],u.time+v.time);
			}
		}
	}
	for(int i=1;i<=n;i++){
		G[i][i]=0;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<G[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int mid=1;mid<=n;mid++){
		for(int u=1;u<=n;u++){
			if(u==mid){
				continue;
			}
			for(int v=1;v<=n;v++){
				if(u==v||mid==v){
					continue;
				}
				G[u][v]=min(G[u][v],G[u][mid]+G[mid][v]);
			}
		}
 	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<"0\n";
			continue;
		}
		int ans=inf;
		for(cross i : sta[x]){
			int u=i.line;
			for(cross j : sta[y]){
				int v=j.line;
//				cout<<u<<" -> "<<v<<" ( "<<w[i.stat]<<" + "<<w[j.stat]<<" + "<<i.time<<" + "<<j.time<<" + "<<G[u][v]<<" )\n"; 
				ans=min(ans,G[u][v]+w[i.stat]+w[j.stat]+i.time+j.time); 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
地铁线路->点 
经过第 v 个地铁站的线路数均不超过 20
每个地铁站d^2=400预处理 
多源最短路预处理：500^3=125*1e6=1e8+ 
每次询问：
枚举可以作为起点和终点的线路：400
*/
