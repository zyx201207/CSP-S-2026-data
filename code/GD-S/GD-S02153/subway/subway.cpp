#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pli=pair<ll,int>;
const int nm=1e5+5,mm=5e5+5;
int c,n,m,d,q,w[mm];
ll ltl[505],lts[mm],ans[nm];//到线的最短路和到点的 
vector<pii>cas[505],cal[mm];//线路能到的 站能到的 
struct p{
	int x,y,id;
	bool operator<(const p&ot)const{
		return x<ot.x;
	}
};
void bfs(int b){
	priority_queue<pli,vector<pli>,greater<pli>>q1,q2; 
	q1.push({0,b});
	for(int i=1;i<=m;i++)lts[i]=1e18;
	for(int i=1;i<=n;i++)ltl[i]=1e18;
	lts[b]=0;
	//cout<<b<<endl;
	while(!q1.empty()){
		while(!q1.empty()){
			long long x=q1.top().first;
			int id=q1.top().second;
			q1.pop();
			if(lts[id]!=x)continue;//不是最短 
			for(pii nl:cal[id]){//相邻的线 
				int lid=nl.first,nd=nl.second;
				if(ltl[lid]>x+nd){//更短连接 
					ltl[lid]=x+nd;
					q2.push({ltl[lid],lid});//重测的 
				}
			}
		}//更新线路 
		while(!q2.empty()){
			long long x=q2.top().first;
			int id=q2.top().second;
			q2.pop();
			if(ltl[id]!=x)continue;
			for(pii ns:cas[id]){//相邻的点 
				int sid=ns.first,nd=ns.second;
				if(lts[sid]>x+nd){//更短连接 
					lts[sid]=x+nd;
					q1.push({lts[sid],sid});//重测 
				}
			}
		}//更新
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			cas[i].push_back({a,t});//走到a站台消耗t时间 
			cal[a].push_back({i,t});//走到i线消耗t时间 
		}
	}
	priority_queue<p>pq;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		pq.push({x,y,i});
	}//查询 
	while(!pq.empty()){
		vector<p>v;
		v.push_back(pq.top());
		int b=v[0].x;//起点 
		pq.pop();
		while(!pq.empty()&&pq.top().x==v[0].x){
			v.push_back(pq.top());
			pq.pop();
		}//同一起点的 
		bfs(v[0].id);
		for(p x:v)ans[x.id]=lts[x.y]+w[x.y]+w[b];//到终点的路程 
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
}
