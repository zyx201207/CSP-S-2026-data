#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int INF=1e9;
struct nn{
	int h,g;
};
int c,n,m,d,q;
int w[N],vis[N],x[600],dis[600];
vector<int> t[600],a[600],vv[600];
vector<nn> v[N];
struct kk{
	int id,l,sum;
};
queue<kk> p;
int bfs(int r,int y){
		int minn=INF;
		while(!p.empty()) p.pop();
		p.push((kk){r,-1,w[r]+w[y]});
		memset(dis,0x3f,sizeof dis);
		while(!p.empty()){
			kk top=p.front();
			p.pop();
			for(int i=0;i<v[top.id].size();i++){
				if(dis[v[top.id][i].h]<top.sum) continue;
				else dis[v[top.id][i].h]=top.sum;
				if(v[top.id][i].h==top.l) continue;
				for(int j=0;j<a[v[top.id][i].h].size();j++){
					if(a[v[top.id][i].h][j]==top.id){
						continue;
					}
					if(a[v[top.id][i].h][j]==y){
						minn=min(minn,top.sum+t[v[top.id][i].h][v[top.id][i].g]+t[v[top.id][i].h][j]);
						break;
					}
					if(vis[a[v[top.id][i].h][j]]==1){
						continue;
					}
					p.push((kk){a[v[top.id][i].h][j],i,top.sum+t[v[top.id][i].h][v[top.id][i].g]+t[v[top.id][i].h][j]});
				}
			}
		}
		return minn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<=x[i];j++){
			int u,o;
			cin>>u>>o;
			a[i].push_back(u);
			t[i].push_back(o);
			vv[i].push_back(0);
			v[u].push_back((nn){i,j-1});
			vis[u]++;
		}
	}
	while(q--){
		int r,y;
		cin>>r>>y;
		cout<<bfs(r,y)<<"\n";
	}
}
