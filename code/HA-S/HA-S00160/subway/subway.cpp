#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e6+10;
const ll inf=1e18;
int c,n,m,d,q;
int w[M];
vector<int> dian[M];
int ori[M];//to find where is the point from
int cnt;//the true number of points
vector<int> tu[M],quan[M];
void add_edge(int u,int v,int t){
	tu[u].push_back(v);
	quan[u].push_back(t);
}
ll dis[M];
int done[M];
struct node{
	int u;
	ll dis;
	friend bool operator < (node i,node j){
		return i.dis>j.dis;
	}
};
ll dijkstra(int S,int T){
	priority_queue<node> que;
	for(int i=0;i<=cnt;i++){
		dis[i]=inf;done[i]=0;
	}
	que.push((node){dian[S][0],0});
	dis[dian[S][0]]=0;
	while(!que.empty()){
		int u=que.top().u;
		if(dian[T][0]==u){
			return que.top().dis;
		}
		que.pop();
		if(done[u])continue;
		done[u]=1;
		for(int i=0;i<tu[u].size();i++){
			int v=tu[u][i];
			ll t=quan[u][i];
			if(dis[v]>dis[u]+t){
				dis[v]=dis[u]+t;
				que.push((node){v,dis[v]});
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		++cnt;
		dian[i].push_back(cnt);
		//the sign point of the station
	}
	for(int i=1;i<=n;i++){
		int k;
		int pre=-1;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			++cnt;
			ori[cnt]=a;
			dian[a].push_back(cnt);
			add_edge(cnt,dian[a][0],t);
			add_edge(dian[a][0],cnt,t);
			if(pre!=-1)add_edge(pre,cnt,0);
			if(pre!=-1)add_edge(cnt,pre,0);
			pre=cnt;
		}
	}
	for(int i=1;i<=q;i++){
		int S,T;
		cin>>S>>T;
		cout<<w[S]+w[T]+dijkstra(S,T)<<'\n';
	}
	return 0;
}
