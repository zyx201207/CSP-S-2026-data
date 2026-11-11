#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int N=510;
int c,n,m,d,q;
struct node{
	int v,w;
};
vector<node> e[3*N];
bool vis[3*N];
int bfs(int s,int t){
	queue<pair<int,int> > q;
	q.push({s+2*m,0});
	vis[s+2*m]=1;
	int ans=0x3f3f3f3f;
	while(!q.empty()){
		int x=q.front().first,z=q.front().second;
		q.pop();
//		cout<<"x:"<<x<<" z:"<<z<<endl;
		if(x==t+2*m) ans=min(ans,z);
		for(auto i:e[x]){
			int v=i.v;
			int w=i.w;
			if(vis[v]) continue;
			q.push({v,z+w});
			vis[v]=1;
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		int x;
		cin>>x;
		e[i+2*m].push_back({i,x});
		e[i].push_back({i+2*m,x});
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		int lx=0;
		for(int j=1;j<=k;++j){
			int x,y;
			cin>>x>>y;
			if(j!=1){
				e[lx+m].push_back({x+m,0});
				e[x+m].push_back({lx+m,0});
			}
			e[x+m].push_back({x,y});
			e[x].push_back({x+m,y});
			lx=x;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<endl;
		cout<<endl;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}

