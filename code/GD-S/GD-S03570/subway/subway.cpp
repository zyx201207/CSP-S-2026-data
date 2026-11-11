#include<bits/stdc++.h> 
using namespace std;
#define maxn 510005
//rp++
struct node{
	long long w;//从每个地铁站的地铁口走到站厅需要的时间
	long long t[21];//表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
}pot[maxn];
struct p{
	long long ind,w,f;
	friend bool operator < (p a,p b){
		return a.w > b.w;
	}
};
struct ed{
	long long v,f;
};
vector<ed> e[maxn]; 
int vis[maxn];
long long c,n,m,d,q;
long long w[maxn];
void add(int u,int v,int f){
	e[u].push_back({v,f});
	//cout << u << endl << v << endl;
}
long long dis[maxn];

int dij(int s,int fin){
	for(int i = 1;i <= m;i++){
		dis[i] = INT_MAX;
		vis[i] = 0;
	}
	priority_queue<p> q;
	int res = 0;
	q.push({s,s,-1});
	dis[s] = 0;
	
	while(!q.empty()){
		int u = q.top().ind,w = q.top().w;
		q.pop();
		if(vis[u])continue;
		int f = q.top().f;
		//cout << u << endl;
		//cout << e[u].size() << endl;
		
		vis[u] = 1;
		for(int i = 0;i < e[u].size();i++){
			int v = e[u][i].v;
			int fr = e[u][i].f;
			
			
			if(fr != f){
				int qw;
				if(u == s && f == -1){
					qw = pot[u].t[fr];
				}
				else qw = pot[u].t[f]+pot[u].t[fr];
				
				if(dis[v] > dis[u]+qw){
					dis[v] = dis[u]+qw;
					if(v == fin){
						res = fr;
					}
				}
			}
			else{
				if(dis[v] > dis[u]){
					dis[v] = dis[u];
					if(v == fin){
						res = f;
					}
				}
			}
			q.push({v,dis[v],fr});
			//cout << v << endl;
		}
	}
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> pot[i].w;
	}
	
	int x,k;
	for(int i = 1;i <= n;i++){
		cin >> k;
		int lst = 0;
		for(int j =1;j<=k;j++){
			cin >> x;

			cin >> pot[x].t[i];
			if(lst == 0){
				lst = x;
				
			}
			else{
				//cout << lst << " " << x << endl;
				add(lst,x,i);
				add(x,lst,i);
				lst = x;
			}
		}
	}
	
	int qx,qy;
	for(int i = 1;i <= q;i++){
		cin >> qx >> qy;
		long long ww = dij(qx,qy);
		cout << dis[qy]+pot[qx].w+pot[qy].w+pot[qy].t[ww] << endl;
	}
	return 0;
}
