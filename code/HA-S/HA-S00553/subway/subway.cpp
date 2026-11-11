#include<bits/stdc++.h>
#define in :
#define int long long
using us=unsigned;
using namespace std;
template<typename T>
void read(T& a) {
	cin>>a;
	return void();
}
template<typename T,typename... Args>
void read(T& a,Args&... args) {
	read(a);
	read(args...);
	return void();
}
template<typename T>
void print(T a) {
	cout<<a;
	return void();
}
template<typename T,typename... Args>
void print(T a,Args... args) {
	print(a);
	print(args...);
	return void();
}
const int N = 5e5;
int c,n,m,d,q;
struct Node {
	int to;
	int time;
};
int w[N+10];//地铁口到站厅
vector<Node>path[N+10];//.to为经过第i站的线路,.time为到该路线站台的时间
int k[510];//第i条线路经过k[i]个站台
vector<Node>station[510];//第i条线路经过station[i]内的所有站
int dis[510][510];//从i号路线的某个站台到j号路线的某个站台
signed main() noexcept{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	read(c,n,m,d,q);
	for(us i=1; i<=m; i++) {
		read(w[i]);
	}
	for(us i=1; i<=n; i++) {
		read(k[i]);
		int a,t;//a表示第i个线路经过a这个站,t表示从a站厅到该线路站台的时间
		for(us j=1; j<=k[i]; j++) {
			read(a,t);
			path[a].push_back({i,t});
			station[i].push_back({a,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(us i=1; i<=n; i++) {
		dis[i][i]=0;
	}
	for(us i=1; i<=n; i++) {
		for(auto xx in station[i]) {
			int a=xx.to;
			int t=xx.time;
			//i线过a站,i线到a站需要的时间为t
			for(auto yy in path[a]) {
				int l=yy.to;
				int tt=yy.time;
				//l线过a站,a站到l线时间为t
//				print("WR: ",t,' ',tt,'\n');
				dis[i][l]=min(dis[i][l],t+tt);
				dis[l][i]=dis[i][l];
			}
		}
	}
	for(us k=1; k<=n; k++) {
		for(us i=1; i<=n; i++) {
			for(us j=1; j<=n; j++) {
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++) {
//		for(int j=i+1;j<=n;j++) {
//			print("i: ",i," j: ",j," ",dis[i][j],'\n');
//		}
//	}
	while(q--) {
		//x为出发点,y为目的地
		int x,y;
		read(x,y);
		int ans=1e18;
		for(auto xx in path[x]) {
			int j=xx.to;
			int t=xx.time;
			//j线过x,j线到x需要t时间
			for(auto yy in path[y]) {
				int l=yy.to;
				int tt=yy.time;
				//l线过y,需要时间tt
//				print(t,' ',tt,'\n');
				ans=min(ans,t+tt+dis[j][l]);
			}
		}
		ans+=w[x]+w[y];
		print(ans,'\n');
	}
	return 0;
}