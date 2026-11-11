#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ll;
ll thi,n,m,d,q;
ll w[5010],k[510],a[510][50010],t[510][50010],x,y,dis[50010][510];
vector<ll>g[510];
void dfs(ll pos,ll con){
	//cout<<pos<<' '<<con<<' '<<dis[pos][con]<<'\n';
	ll st=dis[pos][con];
	if(con==0){
		if(st+w[pos]<dis[pos][1]){
			dis[pos][1]=st+w[pos];
			dfs(pos,1);
		}
		for(ll i=0;i<g[pos].size();i++){
			if(st+t[g[pos][i]][pos]<dis[pos][g[pos][i]+1]){
				dis[pos][g[pos][i]+1]=st+t[g[pos][i]][pos];
				dfs(pos,g[pos][i]+1);
			}
		}
	}else if(con==1){
		if(st+w[pos]<dis[pos][0]){
			dis[pos][0]=st+w[pos];
			dfs(pos,0);
		}
	}else{
		if(st+t[con-1][pos]<dis[pos][0]){
			dis[pos][0]=st+t[con-1][pos];
			dfs(pos,0);
		}
		for(ll i=1;i<=k[con-1];i++){
			if(st<dis[a[con-1][i]][con]){
				dis[a[con-1][i]][con]=st;
				dfs(a[con-1][i],con);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>thi>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) scanf("%d",&w[i]);
	for(ll i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(ll j=1;j<=k[i];j++){
			scanf("%d",&a[i][j]);
			g[a[i][j]].push_back(i);
			scanf("%d",&t[i][a[i][j]]);
		}
	}
	while(q--){
		memset(dis,0x3f,sizeof dis);
		cin>>x>>y;
		//cout<<x<<' '<<y<<'\n';
		dis[x][1]=0;
		dfs(x,1);
		cout<<dis[y][1]<<'\n'; 
	}
	//cout<<dis[1][0];
	return 0;
}
