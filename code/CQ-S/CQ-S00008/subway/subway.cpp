#include<bits/stdc++.h>

using namespace std;
const int N=5e5+7;
int c,n,m,d,Q,w[N],idx,k[666],dis[10*N],num,tk,maxs;
struct node{
	int x,t,subway;
};
vector<node> g[10*N];
priority_queue<pair<int,pair<int,int> > > q;
void bfs(int u,int ed){
	while(!q.empty()) q.pop();
	q.push({0,{u,0}});
	maxs=0;
	while(!q.empty()){
		pair<int,pair<int,int> > f=q.top();
		q.pop();
		if(f.second.first==ed){
			cout<<-f.first-f.second.second+w[u]+w[ed]<<"\n";
			return ;
		}
		for(auto v : g[f.second.first]){
			if(!dis[v.x]||dis[v.x]>-f.first){
				dis[v.x]=-f.first+v.t;
				maxs=max(maxs,v.x);
				q.push({f.first-v.t,{v.x,f.second.second+v.subway}}); 
			}
		}
	}
}
struct tg{
	int step,now,sub;
};
queue<tg> q1;
void bfs1(int u,int ed){
	while(!q1.empty()) q1.pop();
	q1.push({0,u,0});
	maxs=0;
	while(!q1.empty()){
		tg f=q1.front();
		q1.pop();
		if(f.now==ed){
			cout<<f.step-f.sub+w[u]+w[ed]<<"\n";
			return ;
		}
		for(auto v : g[f.now]){
			if(!dis[v.x]){
				dis[v.x]=1;
				maxs=max(maxs,v.x);
				q1.push({f.step+v.t,v.x,f.sub+v.subway}); 
			}
		}
	}
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	idx=m;
	for(int i = 1 ; i <= m ; i++) cin>>w[i];
	for(int i = 1 ; i <= n ; i++){
		cin>>k[i];
		for(int j = 1 ; j <= k[i] ; j++){
			cin>>num>>tk;
			++idx;
			g[num].push_back({idx,tk,0});
			g[idx].push_back({num,tk,0});
			if(j!=1){
				g[idx].push_back({idx-1,1,1});
				g[idx-1].push_back({idx,1,1});
			}
		}
	}

	while(Q--){
		int x,y;
		cin>>x>>y;
		for(int i = 1 ; i <= maxs ; i++){
			dis[i]=0;
		}
		if(c>=9&&c<=15){
			bfs1(x,y);
		}
		else bfs(x,y);
	}
	return 0;
}

