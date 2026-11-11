#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace lp{
	int n,m,dt,q,a[500005],x,y,z,b[505][505],d[505][505],ui,ans;
	bool vt[505];
	struct op{int y,w;};
	struct op2{
		int fx,fy;
		bool operator<(const op2 &yu)const{return fy>yu.fy;}
	};
	vector<op>rt[500005],v[505];
	priority_queue<op2>p;
	void dij(int x){
		memset(vt,0,sizeof(vt)),d[x][x]=0,p.push({x,d[x][x]});
		while(p.size()){
			ui=p.top().fx,p.pop();
			if(vt[ui])continue;
			vt[ui]=true;
			for(auto i:v[ui]){
				if(d[x][i.y]>d[x][ui]+i.w){
					d[x][i.y]=d[x][ui]+i.w;
					if(!vt[i.y])p.push({i.y,d[x][i.y]});
				}
			}
		}
	}
	signed main(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>x>>n>>m>>dt>>q;
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			cin>>x;
			for(int j=1;j<=x;j++)cin>>y>>z,rt[y].push_back({i,z});
		}
		memset(b,0x7f,sizeof(b));
		for(int i=1;i<=m;i++){
			x=rt[i].size();
			for(int j=0;j<x;j++){
				for(int k=j+1;k<x;k++)b[rt[i][j].y][rt[i][k].y]=min(b[rt[i][j].y][rt[i][k].y],rt[i][j].w+rt[i][k].w),b[rt[i][k].y][rt[i][j].y]=b[rt[i][j].y][rt[i][k].y];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)if(b[i][j]!=0x7f7f7f7f7f7f7f7f)v[i].push_back({j,b[i][j]}),v[j].push_back({i,b[j][i]});
		}
		memset(d,0x7f,sizeof(d));
		for(int i=1;i<=n;i++)dij(i);
		while(q--){
			cin>>x>>y,ans=0x7f7f7f7f7f7f7f7f;
			for(auto i:rt[x]){
				for(auto j:rt[y])ans=min(ans,a[x]+i.w+d[i.y][j.y]+j.w+a[y]);
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
}
signed main(){
	lp::main();
	return 0;
}

