#include<bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
#define PLI pair<LL,int>
using namespace std;
int cid,n,m,d,Q;
namespace sub1{
	const int N=1210;
	vector<PII>g[N];
	LL dist[N];
	bool st[N];
	void add(int a,int b,int c){
		g[a].emplace_back(b,c);
	}
	void Dijkstra(int s,int e){
		memset(dist,0x3f,sizeof(dist));
		memset(st,false,sizeof(st));
		dist[s]=0;
		priority_queue<PLI,vector<PLI>,greater<PLI>>q;
		q.push({0,s});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(st[u]) continue;
			st[u]=true;
			//cout<<u<<" ";
			for(auto &[j,w]:g[u]){
				//if(u==12) cout<<j<<" "<<w<<"\n";
				if(dist[j]>dist[u]+w){
					dist[j]=dist[u]+w;
					q.push({dist[j],j});
				}
			}
		}
		cout<<dist[e]<<"\n";
	}
	void solve(){
		for(int i=1;i<=m;i++){
			int x;
			cin>>x;
			add(i,i+m,x);
			add(i+m,i,x);
		}
		int num=m+m;
		for(int i=1;i<=n;i++){
			int cnt;
			cin>>cnt;
			int start=num+1;
			while(cnt--){
				int id,t;
				cin>>id>>t;
				num++;
				add(id+m,num,t);
				add(num,id+m,t);
			}
			for(int i=start;i<num;i++){
				//cout<<i<<" "<<i+1<<"\n";
				add(i,i+1,0);
				add(i+1,i,0);
			}
		}
		while(Q--){
			int s,e;
			cin>>s>>e;
			Dijkstra(s,e);
		}
	}
}
namespace sub2{
	const int N=3010;
	vector<PII>g[N];
	LL dist[N][N];
	bool st[N];
	void add(int a,int b,int c){
		g[a].emplace_back(b,c);
	}
	void Dijkstra(int s){
		memset(dist[s],0x3f,sizeof(dist[s]));
		memset(st,false,sizeof(st));
		dist[s][s]=0;
		priority_queue<PLI,vector<PLI>,greater<PLI>>q;
		q.push({0,s});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(st[u]) continue;
			st[u]=true;
			//cout<<u<<" ";
			for(auto &[j,w]:g[u]){
				//if(u==12) cout<<j<<" "<<w<<"\n";
				if(dist[s][j]>dist[s][u]+w){
					dist[s][j]=dist[s][u]+w;
					q.push({dist[s][j],j});
				}
			}
		}
	}
	void solve(){
		for(int i=1;i<=m;i++){
			int x;
			cin>>x;
			add(i,i+m,x);
			add(i+m,i,x);
		}
		int num=m+m;
		for(int i=1;i<=n;i++){
			int cnt;
			cin>>cnt;
			int start=num+1;
			while(cnt--){
				int id,t;
				cin>>id>>t;
				num++;
				add(id+m,num,t);
				add(num,id+m,t);
			}
			for(int i=start;i<num;i++){
				//cout<<i<<" "<<i+1<<"\n";
				add(i,i+1,0);
				add(i+1,i,0);
			}
		}
		for(int i=1;i<=m;i++){
			Dijkstra(i);
		}
		while(Q--){
			int s,e;
			cin>>s>>e;
			cout<<dist[s][e]<<"\n";
		}
	}
}
namespace sub3{
	const int N=4e4+10;
	vector<PII>g[N];
	LL w[N],dist[N];
	bool st[N];
	int num;
	void add(int a,int b,int c){
		g[a].emplace_back(b,c);
	}
	void bfs(int s,int e){
		for(int i=1;i<=num;i++) dist[i]=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=num;i++) st[i]=false;
		dist[s]=0;
		deque<PLI>q;
		q.push_front({0,s});
		while(!q.empty()){
			int u=q.front().second;
			q.pop_front();
			if(st[u]) continue;
			st[u]=true;
			//cout<<u<<" ";
			for(auto &[j,w]:g[u]){
				//if(u==12) cout<<j<<" "<<w<<"\n";
				if(dist[j]>dist[u]+w){
					dist[j]=dist[u]+w;
					if(!w) q.push_front({dist[j],j});
					else q.push_back({dist[j],j});
				}
			}
		}
		cout<<dist[e]<<"\n";
	}
	void solve(){
		for(int i=1;i<=m;i++){
			cin>>w[i];
			add(i,i+m,w[i]);
			add(i+m,i,w[i]);
		}
		num=m+m;
		for(int i=1;i<=n;i++){
			int cnt;
			cin>>cnt;
			int start=num+1;
			while(cnt--){
				int id,t;
				cin>>id>>t;
				num++;
				add(id,num,t);
				add(num,id,t);
			}
			for(int i=start;i<num;i++){
				//cout<<i<<" "<<i+1<<"\n";
				add(i,i+1,0);
				add(i+1,i,0);
			}
		}
		while(Q--){
			int s,e;
			cin>>s>>e;
			bfs(s,e);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>cid>>n>>m>>d>>Q;
	if(cid>=0&&cid<=8) sub1::solve();
	else if(cid>=9&&cid<=11) sub2::solve();
	else if(cid>=12&&cid<=15) sub3::solve();
	return 0;
}