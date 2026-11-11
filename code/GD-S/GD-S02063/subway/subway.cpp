#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int c,n,m,d,q;
int w[500010];
struct asdf{
	int nx,v;
	bool operator < (const asdf & ot)const{
		return ot.v <v;
	}
};
vector<asdf>g[501010];
int vis[501010];
int dj(int s,int e,int uu){
	priority_queue<asdf>pq;
	pq.push({s,w[s]+w[e]});
	while(!pq.empty()){
		asdf b=pq.top();
		pq.pop();
		if(vis[b.nx]==uu)continue;
		vis[b.nx]=uu;
		if(b.nx==e)return b.v;
		for(int i=0;i<g[b.nx].size();i++){
			pq.push({g[b.nx][i].nx,b.v+g[b.nx][i].v});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		//dis[i]=1e9;
	}
	int A,T;
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>A>>T;
			g[i+m].push_back({A,T});
			g[A].push_back({i+m,T});
		}
		//dis[i+m]=1e9;
	}
	int L,R;
	for(int i=1;i<=q;i++){
		cin>>L>>R;
		cout<<dj(L,R,i)<<"\n";
		
	}
	
	return 0;
}
