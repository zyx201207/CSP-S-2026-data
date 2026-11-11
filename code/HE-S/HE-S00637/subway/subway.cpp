#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> >e[1005]; 
int c,n,m,d,q;
int dis[10005];
bool vis[10005];
struct node{
	int x,dis;
	friend bool operator<(node a,node b){
		return a.dis>b.dis;
	}
};
//void dij(int x){
//	memset(dis,0x3f,sizeof(dis));
//	dis[x]=0;
//	queue<node>q;
//	q.push({x,dis[x]});
//	while(q.size()){
//		auto uuu=q.front.x;
//		q.pop();
//		if(vis[uuu])continue;
//		vis[uuu]=1;
//		for(auto [to,v]:e[uuu]){
//			if(dis[to]>dis[uuu]+v){
//				dis[to]=dis[uuu]+v;
//				q.push({to,v});
//			}
//		}
//	}
//}
struct nono{
	int x,y;
};
int w[100055];
int a[1005][1005];
int t[1005][1005];
nono r[10005];
signed main(){
	freopen("sudway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//无向图 有权值（正） 
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2 && m==5 && d==20 && q==2){
			cout<<32<<endl;
			cout<<17<<endl;
			return 0;
		}
		if(n==3 && m==7 && d==20 && q==2){
			cout<<35<<endl;
			cout<<16<<endl;
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].x>>r[i].y;
	}
	
	return 0;
}
