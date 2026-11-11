#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e4+5;
int c,n,m,d,q,maxn;
int k[N],w[M];
int dis[M];
int a[N][M],t[N][M];
vector <pair<int,int>> v[M];
void dij(int st){
	for(int i=1;i<=maxn;i++)dis[i]=0x7fffffff;
	priority_queue <pair<int,int>> q;
	dis[st]=0;
	q.push({0,st});
	while(!q.empty()){
		int d=-q.top().first;
		int x=q.top().second;
		q.pop();
		if(dis[x]<d)continue;
		for(auto t:v[x]){
			int y=t.first;
			int z=t.second;
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				q.push({-dis[y],y});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>c>>n>>m>>d>>q;
	//c 测试点编号(无用)
	//n n条地铁线
	//m m个站台
	//d 最多 d条路线通过(无用)
	//q q次询问 
	for(int i=1;i<=m;i++)cin>>w[i];// 站台 <--> 站厅   时间 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];// 第 i号线的第 j个站 
			maxn=max(maxn,a[i][j]);
			cin>>t[i][j];// 第 i号线的第 j个站 <-> 站厅   时间 
		}
		for(int j=1;j<=k[i];j++){
			int x=a[i][j];
			for(int tp=j+1;tp<=k[i];tp++){
				int y=a[i][tp];
				int w=t[i][j]+t[i][tp];
				v[x].push_back({y,w});
				v[y].push_back({x,w});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
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
*/

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
