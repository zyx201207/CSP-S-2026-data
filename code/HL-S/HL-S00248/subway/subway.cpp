#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[50005];
struct{
	int a,t;
}p[505][100005];
struct node{
	int v,w;
};
struct NODE{
	int v,w,fa;
};
vector<node> G[500005];
int bfs(int x,int y){
	int kk=1e9;
	queue<NODE>q;
	q.push({x,0,0});
	while(!q.empty()){
		NODE now=q.front();
		if(now.v==y){
			kk=min(kk,now.w);
		}
		q.pop();
		for(int i=0;i<G[now.v].size();i++){
			if(G[now.v][i].v==now.fa){
				continue;
			}
			q.push({G[now.v][i].v,now.w+G[now.v][i].w,now.v});
		}
	}
	return kk;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int ppp=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>p[i][j].a>>p[i][j].t;
			G[ppp*i+p[i][j].a].push_back({p[i][j].a,p[i][j].t});
			G[p[i][j].a].push_back({ppp*i+p[i][j].a,p[i][j].t});
		}
		for(int j=1;j<k;j++){
			G[ppp*i+p[i][j].a].push_back({ppp*i+p[i][j+1].a,0});
			G[ppp*i+p[i][j+1].a].push_back({ppp*i+p[i][j].a,0});
		}
	}
	while(q--){
//		memset(vis,0,sizeof vis);
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		cout<<bfs(x,y)+ans<<endl;
	}
	return 0;
}

