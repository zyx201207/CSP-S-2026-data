#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int MX = 1e17;

int c,n,m,d,q;
int w[500010];
vector<pair<int,int>>e[500010];//表示每一个站，所能经过的线路编号。 
int f[510][510];

void dj(int s){
	priority_queue<pair<int,int>>q;
	
	for(int i=1;i<=n;i++){
		if(i==s) continue;
		q.push({-f[s][i],i});
	}
	
	while(q.size()){
		int k=q.top().second;
		q.pop();
		for(int j=1;j<=n;j++){
			if(j==k) continue;
			if(f[s][j]>f[s][k]+f[k][j]){
				
				f[s][j]=f[s][k]+f[k][j];
				q.push({-f[s][j],j});
			}
		}
	}
	return ;
}

signed main( ){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int rht,qzx;
			scanf("%lld%lld",&rht,&qzx);
			e[rht].push_back({i,qzx});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			f[i][j]=MX;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=0;i<e[k].size();i++){
			for(int j=i+1;j<e[k].size();j++){
				auto x=e[k][i],y=e[k][j];
				f[x.first][y.first]=min(f[x.first][y.first],x.second+y.second);
				f[y.first][x.first]=min(f[y.first][x.first],x.second+y.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dj(i);
	}
	while(q--){
		int x,y;scanf("%lld%lld",&x,&y);
		int ans=MX;
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[y].size();j++){
				auto dx=e[x][i],dy=e[y][j];
				int s=f[dx.first][dy.first]+dx.second+dy.second;
				ans=min(ans,s);
			}
		}
		ans=ans+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}

