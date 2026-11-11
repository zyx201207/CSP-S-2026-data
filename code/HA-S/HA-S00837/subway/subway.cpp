#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define ft first
#define sd second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rem(i,a,b) for(int i=(a);i>=(b);i--)
#define PII pair<int,int>
using namespace std;

const LL N=505,M=5e5+10,INF=0x3f3f3f3f3f3f3f3f;
LL SUB,n,m,d,q;
LL w[M],dis[N][N];
vector<PII> g[M];

int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	//freopen("subway1.in","r",stdin);freopen("std.out","w",stdout);//fc /W std.out subway.ans
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>SUB>>n>>m>>d>>q;
	rep(i,1,m) cin>>w[i];
	rep(i,1,n){
		int ki;cin>>ki;
		while(ki--){
			int x,y;cin>>x>>y;
			g[x].pb({i,y});
		}
	}
	rep(i,1,n) rep(j,1,n) dis[i][j]=i==j?0:INF;
	rep(t,1,m){
		int sz=g[t].size();
		rep(i,0,sz-1){
			LL x1=g[t][i].ft,y1=g[t][i].sd;
			rep(j,i+1,sz-1){
				LL x2=g[t][j].ft,y2=g[t][j].sd;
				dis[x1][x2]=dis[x2][x1]=min(dis[x1][x2],y1+y2);
			}
		}
	}
	rep(k,1,n) rep(i,1,n) rep(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		LL tmp=INF;
		for(auto d1:g[x]) for(auto d2:g[y]) tmp=min(tmp,dis[d1.ft][d2.ft]+d1.sd+d2.sd);
		cout<<tmp+w[x]+w[y]<<'\n';
	}
	return 0;
}
