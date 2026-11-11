#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+3;
int C,T,dis[MAXN];
int n,d,pos[MAXN];
vector <pair<int,int>> g[MAXN];
struct node{
	int u,step;
	string path;
	node(int aa,int bb,string cc):u(aa),step(bb),path(cc) {} 
	bool operator<(const node& other) const{
		return step>other.step;
	}
};
inline bool dijkstra(int S,int E){
	memset(dis,0x3f,sizeof(dis));
	priority_queue <node> q;
	vector <pair<int,string>> res;
	string start="";
	start+=(char)(S+'0');
	q.emplace(S,0,start);
	while(!q.empty()){
		auto cur=q.top();
		int u=cur.u,step=cur.step;
		string path=cur.path;
		q.pop();
		if(step>dis[u]) continue;
		if(u==E) res.emplace_back(step,path);
		for(const auto& edge:g[u]){
			int v=edge.first,w=edge.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				string npath=path;
				npath+=(char)(v+'0');
				q.emplace(v,dis[v],npath);
			}
		}
	}
	int cnt=0;
	string res_path="-1";
	for(const auto& x:res){
		int step=x.first;
		string path=x.second;
		if(step==dis[E]){
			if(res_path=="-1") res_path=path;
			else cnt+=(int)(path!=res_path);
		}
	}
	return cnt==2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> C >> T;
	while(T--){
		int ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++) cin >> pos[i];
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j && abs(pos[i]-pos[j])<=d) g[i].emplace_back(j,abs(pos[i]-pos[j]));
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j && dijkstra(i,j)) ans++;
		cout << ans << '\n';
	}
	return 0;
}
