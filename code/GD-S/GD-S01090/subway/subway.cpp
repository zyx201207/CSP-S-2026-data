#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define pb push_back
#define V vector
const int N=510,M=5e5+10,INF=4e18;
int w[M],k[N];
V<int>a[N],t[N];
int c,n,m,d,q;
struct edge{
	int to,w;
};
V<edge>line[M];//第i个站所有的线路 
V<edge>newline[M];//第i个站到第j条线路的最小代价 
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	FOR(i,1,m)cin>>w[i];
	FOR(i,1,n){
		int k;cin>>k;
		a[i].resize(k+1,0);
		t[i].resize(k+1,0);
		FOR(j,1,k){
			cin>>a[i][j]>>t[i][j];
			line[a[i][j]].pb({i,t[i][j]});
		}
	}
	FOR(i,1,n) FOR(j,1,n) dis[i][j]=INF;
	FOR(i,1,n){//枚举线路 
		FOR(j,1,(int)a[i].size()-1){//枚举该线路相连的站 
			int sta=a[i][j],time1=t[i][j];
			for(auto lls:line[sta]){//枚举这个站相连的线路 
				int line2=lls.to,time2=lls.w;
				if(i!=line2){
//					cout<<i<<" "<<line2<<" "<<time1+time2<<"\n";
					dis[i][line2]=min(dis[i][line2],time1+time2);
				}
			}
		}
	}
	FOR(i,1,n) dis[i][i]=0;
	FOR(k,1,n){
		FOR(i,1,n){
			FOR(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	FOR(i,1,m){//枚举站台 
		newline[i]=line[i];
		FOR(j,0,(int)line[i].size()-1){
			int line1=line[i][j].to;
			FOR(k,j+1,(int)line[i].size()-1){
				int line2=line[i][k].to;
				newline[i][j].w=min(newline[i][j].w,line[i][k].w+dis[line1][line2]);
				newline[i][k].w=min(newline[i][k].w,line[i][j].w+dis[line1][line2]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=INF;
		for(auto i:newline[x]){
			for(auto j:newline[y]){
				int line1=i.to,line2=j.to;
				int cost1=i.w,cost2=j.w;
				ans=min(ans,cost1+cost2+dis[line1][line2]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n"; 
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 3 10 0
0 0 0
3 1 100 2 3 3 10
2 1 1 2 2
*/
