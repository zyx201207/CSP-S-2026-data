#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
long long w[505];
vector<int> g[505];
struct node{
	int dian,fa,step;
};
long long bfs(int x,int y){
	queue<node> q;
	q.push({x,0,1});
	while(q.size()){
		auto u = q.front();
		q.pop();
		for(auto v : g[u.dian]){
			if(v == u.fa)
				continue;
			if(v == y){
				return u.step + 1;
			}
			q.push({v,u.dian,u.step+1});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	int ww = 0;//¶¨Öµ 
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=m;i++){
		cin>>k;
		int u = 0;
		for(int j=1,v,w;j<=k;j++){
			cin>>v>>w;
			ww = w;
			if(j>1){
				g[u].push_back(v);
				g[v].push_back(u);
			}
			u = v;
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		int minn = bfs(x,y);
		cout<<minn * ww + w[x] + w[y]<<"\n";
	}
	return 0;
} 
