#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i=n;i<=m;i++)
#define int long long
struct node{
	int to,w;
	bool operator>(const node &x)const{
		return w>x.w;
	}
};
const int N=5e5+10;
int c,n,m,d,qq,w[N],k,tmp[1001],len[1001],dis[1001][1001],u,v;
vector<node>g[N];
bool vis[N];
priority_queue<node,vector<node>,greater<node> >q;
void disj(int now){
	memset(vis,0,sizeof vis);
	dis[now][now]=0;
	q.push({now,dis[now][now]});
	while(!q.empty()){
		int fr=q.top().to;
		int len=q.top().w;
		q.pop();
		if(vis[fr])continue;
		vis[fr]=1;
		for(int i=0;i<g[fr].size();i++){
			node x=g[fr][i];
		//	cout<<x.to<<' '<<dis[now][x.to]<<'\n';
			if(dis[now][x.to]>dis[now][fr]+x.w){
				dis[now][x.to]=dis[now][fr]+x.w;
				q.push({x.to,dis[now][x.to]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	if(1){
		rep(i,1,m)cin>>w[i];
		rep(i,1,n){
			cin>>k;
			rep(i,1,k){
				cin>>tmp[i]>>len[i];
			}
			rep(i,1,k){
				rep(j,1,k){
					if(i==j)continue;
					g[tmp[i]].push_back({tmp[j],len[i]+len[j]});
					g[tmp[j]].push_back({tmp[i],len[i]+len[j]});
					//cout<<tmp[i]<<' '<<tmp[j]<<'\n';
				}
			}
		}
		memset(dis,0x3f,sizeof dis);
		rep(i,1,m){
			disj(i);
		}
		rep(i,1,qq){
			cin>>u>>v;
			cout<<dis[u][v]+w[u]+w[v]<<'\n';
		}
	}
	return 0;
}
