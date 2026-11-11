#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,D,q;
int w[N],d[N],vis[N];
int fd[M][M];
vector<pii>e[N];
vector<pii>line[55];
void dij(int s){
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});
	vis[s]=1;
	d[s]=0;
	while(!q.empty()){
		int dd=q.top().fi,u=q.top().se;
		q.pop();
		if(dd!=d[u])continue;
		for(auto x:e[u]){
			
			int wi=x.fi,v=x.se;
//			cout<<wi<<' '<<v<<endl;
//			cout<<d[u]<<" "<<d[v]<<endl;
			if(d[u]+wi<d[v]){
				d[v]=d[u]+wi;
				q.push({d[v],v});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
		
			e[a].push_back({t,m+i});
			e[m+i].push_back({t,a});
		}
	}
	for(int i=m+1;i<=m+n;i++){
		dij(i);
		for(int j=m+1;j<=m+n;j++){
			fd[i][j]=d[j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	

	
		dij(x);
	
//		for(int i=1;i<=m;i++){
//			cout<<d[i]<<" ";
//		}
		cout<<d[y]+w[x]+w[y]<<'\n';
	}
	/*
		为什么总是有不同的起点和终点啊
		每次换起点跑dij太慢了，但是5e5的点数又不能跑floyd
		每条线路只经过两个点，有什么深意吗 
		想想作为超级源点的换成站的性质。。。
		不会写floyd能不能循环dij啊 
		啊啊啊好难
		n只有500，跑所有的超级源点之间的最短路之后再枚举行不行啊
		为什么过不了大数据 
	*/
}
/*
0 2 5 10 2
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
*/
