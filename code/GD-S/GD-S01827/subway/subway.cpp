#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define sc second
const int N = 505,M = 5e5+10,INF = 1e18;

int read(){
	int num = 0;
	while(true){
		char c = getchar();
		if(!('0'<=c && c<='9')) break;
		num = num*10ll+(int)(c-'0');
	}
	return num;
}
int c,n,m,d,q;
int t[M],w[N][N],ans[M];
vector<int> v[M]; //每个站有关的所有线路
vector<int> p[M]; //有关线路的行走用时 

struct ques{
	int x,y;
}qq[M];
vector<int> st[N]; //每个线路有关的所有询问 

int dis[N],vis[N];

void dj(int s){
	for(int i=0;i<=n;i++) dis[i] = INF,vis[i] = 0;
	dis[s] = 0;
	while(true){
		int u = 0;
		for(int i=1;i<=n;i++)
			if(!vis[i] && dis[i]<dis[u])
				u = i;
		if(!u) break;
		vis[u] = 1;
		for(int i=1;i<=n;i++)
			dis[i] = min(dis[i],dis[u]+w[u][i]);
	}
}
//void dj(int s){
//	for(int i=0;i<=n;i++) dis[i] = INF,vis[i] = 0;
//	dis[s] = 0;
//	priority_queue<pii,vector<pii>,greater<pii> > pq;
//	pq.push({0,s});
//	while(!pq.empty()){
//		int u = pq.top().sc;
//		pq.pop();
//		if(vis[u]) continue;
//		vis[u] = 1;
//		for(int i=1;i<=n;i++){
//			if(dis[u]+w[u][i]<dis[i]){
//				dis[i] = dis[u]+w[u][i];
//				pq.push({dis[i],i});
//			}
//		}
//	}	
//}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i=1;i<=m;i++) t[i] = read();
	for(int i=1;i<=n;i++){
		int k;
		k = read();
		while(k--){
			int s,f;
			s = read(),f = read();
			v[s].push_back(i);
			p[s].push_back(f);
		}
	}
	for(int i=1;i<=q;i++){
		qq[i].x = read(),qq[i].y = read();
		for(auto x:v[qq[i].x]) st[x].push_back(i); //离线询问到线路上 
		ans[i] = INF;
	}
	//预处理距离
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			w[i][j] = INF;
	for(int i=1;i<=m;i++){
		int len = v[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<len;k++){
				if(p[i][j]+p[i][k]<w[v[i][j]][v[i][k]]){
					w[v[i][j]][v[i][k]] = p[i][j]+p[i][k];
					w[v[i][k]][v[i][j]] = w[v[i][j]][v[i][k]];
				}
			}
		}	
	}
	//枚举原线 
	for(int i=1;i<=n;i++){
		dj(i);
		int len = st[i].size();
		for(int j=0;j<len;j++){
			int x = qq[st[i][j]].x,y = qq[st[i][j]].y,id = st[i][j];
			int t0 = 0;
			for(int k=0;k<v[x].size();k++){ //找原线进站用时 
				if(v[x][k]==i){
					t0 = p[x][k];
					break;
				}
			}
			for(int k=0;k<v[y].size();k++){ //指定出站线路 
				int ed = v[y][k];
				ans[id] = min(ans[id],t[x]+t0+dis[ed]+p[y][k]+t[y]);
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}
