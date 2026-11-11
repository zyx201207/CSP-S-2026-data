#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n=0,m=0,c=0,d=0,q=0,k=0,w[500009];
struct N{
	int x=0,y=0,w=0,k=0;
	bool operator> (const N p)const{
		return w>p.w;
	}
};
vector<N> e[500009];
vector<int> ee[600];
priority_queue<N,vector<N>,greater<N> > p;
bool vis[500009][600];
int answ[500009][600];
ll dij(int x,int y){
	if(x==y)cout<<0;
	for(int i=0;i<int(e[x].size());i++){
		N k=e[x][i];
		answ[k.y][k.x]=k.w;
		p.push(k);
	}
	while(p.size()){
		N v=p.top();
		p.pop();
		if(vis[v.y][v.x])continue;
		vis[v.y][v.x]=1;
		//cout<<v.y<<' '<<v.x<<' '<<v.w<<'\n';
		for(int i=0;i<int(e[v.y].size());i++){
			for(int j=0,d=0;j<int(ee[e[v.y][i].x].size());j++){
				if(vis[ee[e[v.y][i].x][j]][e[v.y][i].x])continue;
				d=0;
				if(v.x!=e[v.y][i].x)d=e[v.y][i].w+v.k;
				if(ee[e[v.y][i].x][j]==y)d+=e[v.y][i].w;
				if(answ[ee[e[v.y][i].x][j]][e[v.y][i].x]>v.w+d){
					answ[ee[e[v.y][i].x][j]][e[v.y][i].x]=v.w+d;
					//cout<<e[v.y][i].x<<' '<<ee[e[v.y][i].x][j]<<' '<<v.w<<'\n';
					N g;
					g.x=e[v.y][i].x,g.y=ee[e[v.y][i].x][j],g.w=v.w+d,g.k=e[v.y][i].w;
					p.push(g);
				}
			}
		} 
	}
	ll ans=1e9;
	for(int i=1;i<=n;i++)if(ans>answ[y][i])ans=answ[y][i];
	//cout<<ans<<'\n';
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k=0;
		N u;
		cin>>k;
		while(k--){
			cin>>u.y>>u.w;
			u.x=i,u.k=u.w;
			ee[i].push_back(u.y);
			e[i].push_back(u);
		}
	}
	ll x=0,y=0,ans=0;
	while(q--){
		cin>>x>>y;
		ans=w[x]+w[y];
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				vis[i][j]=0,answ[i][j]=1e9;
		ans+=dij(x,y);
		cout<<ans<<'\n';
	}
	return 0;
}

