#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
int tid,n,m,_,q;
int extra[500005],dis_line[505][505];
vector<pair<int,int>> g[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(dis_line,0x3f,sizeof(dis_line));
	cin>>tid>>n>>m>>_>>q;
	rep(i,1,n) dis_line[i][i]=0;
	rep(i,1,m) cin>>extra[i];
	rep(line,1,n){
		int k;
		cin>>k;
		rep(i,1,k){
			int x,w;
			cin>>x>>w;
			g[x].push_back({line,w});
		}
	}
	rep(i,1,m){
		int sz=g[i].size();
		rep(p1,0,sz-1){
			rep(p2,p1+1,sz-1){
				auto [l1,dis1]=g[i][p1];
				auto [l2,dis2]=g[i][p2];
				int dis=dis1+dis2;
				dis_line[l1][l2]=min(dis_line[l1][l2],dis);
				dis_line[l2][l1]=min(dis_line[l2][l1],dis);
			}
		}
	}
	rep(k,1,n) rep(i,1,n) rep(j,1,n){
		int nw=dis_line[i][k]+dis_line[k][j];
		dis_line[i][j]=min(dis_line[i][j],nw);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=9e18;
		for(auto [l1,dis1]:g[x]){
			for(auto [l2,dis2]:g[y]){
				int val=dis1+dis2;
				val+=dis_line[l1][l2];
				ans=min(ans,val);
			}
		}
		cout<<ans+extra[x]+extra[y]<<'\n';
	}
	return 0;
}
