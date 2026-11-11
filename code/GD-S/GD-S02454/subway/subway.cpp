#include<bits/stdc++.h>
using namespace std;
#define int long long
using p=pair<int,int>;
constexpr int N=500009;
int a[N];
int dist[N];
vector<int> line[N];
map<int,int> f[N]; //f[i][j]=从第x个地铁站站厅到线路i的站台的时间 
	int c,n,m,d,q;
struct node{
	int x,u,v;
}edges[509];
bool operator<(const node& a,const node & b){
	return a.x<b.x; 
};
int get_dist(int x,int y){
	priority_queue<node> q;
	for(int i=1;i<=m;i++){
		dist[i]=1e14;
	}
	dist[x]=0;
	for(auto z:f[x]){
		int to_line=z.first;
		int time=z.second;
		for(int i=0;i<line[to_line].size();i++){
			if(line[to_line][i]!=x)
				q.push({time+f[line[to_line][i]][to_line],x,line[to_line][i]});
		}
	}
	while(!q.empty()){
		node s=q.top();
		int st=s.u,to=s.v,time=s.x;
		q.pop();
		if(dist[to]<=dist[st]+time) continue;
		dist[to]=dist[st]+time;
		for(auto z:f[to]){
			int to_line=z.first;
			int time=z.second;
			for(int i=0;i<line[to_line].size();i++){
				q.push({time+f[line[to_line][i]][to_line],to,line[to_line][i]});
			}
		}
	}
	return dist[y]+a[y]+a[x];
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x,y;
			cin>>x>>y;
			line[i].push_back(x);
			f[x][i]=y;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<get_dist(x,y)<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
