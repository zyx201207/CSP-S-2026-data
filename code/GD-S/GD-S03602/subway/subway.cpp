#include<bits/stdc++.h>
using namespace std;
const int inf=5e5+20;
int c,m,n,d,q;//c,n,m,d,q,分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
vector<int> line[550];
vector<int> map_[inf];
int w[inf],t[100][100];
int dis[inf];bool vis[inf];
queue<int> qu;
void bfs(int x,int y){
	if(vis[x]||vis[y]) return;
	vis[x]=1;
	for(int id:map_[x]) qu.push(id);
	while(!qu.empty()){
		int in=qu.front();
		qu.pop();
		bfs(in,y);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=0,a_,t_;j<k;j++){
			cin>>a_>>t_;
			if(j>0){
				map_[a_].push_back(line[i][j-1]);
				map_[line[i][j-1]].push_back(a_);
			}
			line[i].push_back(a_);
			t[a_][i]=t_;
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		bfs(x,y);
	}
	return 0;
}
