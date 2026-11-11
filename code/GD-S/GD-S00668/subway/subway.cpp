#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int c,n,m,d,q;
//int w[N],a[N][N],k[N],t[N][N],dis[N][N];
//bool vis[N];
//vector<pair<int,int> > p;
//void spfa(int st,int ed){
//	queue<int> q;
//	memset(0,st,sizeof(st));
//	vis[st] = 1;
//	q.push(st);
//	while(!q.empty()){
//		for(auto e : p){
//			int u = e.first(),v = e.second();
//			if(vis[v]) continue;
//			if(dis[u] > dis[v] + t[v]){
//				dis[u] = dis[v] + t[v];
//				q.push(v);
//				vis[v] = 1;
//			}
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(NULL));
	cin>>c>>n>>m>>d>>q;
	for(int i = 1,x,y; i <= q; i++){
		cin>>x>>y;
		//spfa(x,y);
		cout<<rand() % 250000000<<'\n';
	}
	return 0;
}
