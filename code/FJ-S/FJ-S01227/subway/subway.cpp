/*
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
*/
#include<bits/stdc++.h>
using namespace std;
long long c,n,//地铁线路数 
            m,//地铁站数 
            d,//每个地铁站有几条线路 
            q,//出行计划数（问题数）
			w[512345],//地铁口-站厅
			k,//第i条路线经过地铁站数
			x,y,
			u,v,
			t[512][21],
			sx,//起点 
			sy,//终点
			s[512],
			minn;
struct st{
	long long a,//互联地铁站
			  id;//第几条线路 
};
vector<st> e[512];
void dfs(long long x,long long y,long long sum){
	if(x==sy){
		minn=min(minn,sum+t[x][y]);
		return ;
	}
	for(auto tp:e[x]){
		long long u=tp.a,i=tp.id;
		if(s[u]==0){
			s[u]=1;
			if(y==i) dfs(u,i,sum);
			else dfs(u,i,sum+t[x][y]+t[x][i]);
			s[u]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>v;
			if(j==1){
				t[u][i]=v;
				x=u,y=v;
				continue;
			}
			e[x].push_back({u,i});
			e[u].push_back({x,i});
			t[u][i]=v;
			x=u;
		}
	}while(q--){
		minn=1e18;
		cin>>sx>>sy;
		s[sx]=1;
		dfs(sx,0,w[sx]+w[sy]);
		s[sx]=0;
		cout<<minn<<endl;
	}
	return 0;
} 
