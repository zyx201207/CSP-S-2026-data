// I think I've seen this film before,
// And I didn't like the ending...

//Awful feelings. What should I do?
//I know I cannot solve the problem.

//Let's ESCAPE.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
typedef struct Node{
	int v,w;
	Node(){}
	Node(int _v,int _w):v(_v),w(_w){}
} node;
typedef struct QNode{
	int v,p,tmp; ll d;
	QNode(){}
	QNode(int _v,int _p,int _t,ll _d):v(_v),p(_p),tmp(_t),d(_d){}
	bool operator<(const QNode& x)const{ return d<x.d; }
} qnode;
const int N=1e5+5,M=505;
ll a[M][N],t[M][N],w[N],dis[N];
int k[M],c,n,m,d,q,x,y;
vector<node> G[N];
priority_queue<qnode> Q;
int main(){
	freopen("subway2.in","r",stdin);
	freopen("subway2.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][a[i][j]];
		for(int j=2;j<=k[i];j++){
			G[a[i][j-1]].push_back(node(a[i][j],i));
			G[a[i][j]].push_back(node(a[i][j-1],i));
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int i=1;i<=n;i++) dis[i]=1e18;
		dis[x]=0;
		for(size_t i=0;i<G[x].size();i++){
			int v=G[x][i].v,k=G[x][i].w;
			Q.push(qnode(v,k,-1,t[k][x]));
		}
		while(!Q.empty()){
			int u=Q.top().v,pre=Q.top().p,tmp=Q.top().tmp,d=Q.top().d;
			Q.pop();
			for(size_t i=0;i<G[u].size();i++){
				int v=G[u][i].v,k=G[u][i].w;
				if(v==tmp) continue;
				if(k==pre) Q.push(qnode(v,k,u,d));
				else if(d+t[k][u]+t[k][v]>dis[v]){
					Q.push(qnode(v,k,u,d+t[k][u]+t[k][v]));
					dis[v]=d+t[k][u]+t[k][v];
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}

//#include<iostream>
//#include<iomanip>
//#include<algorithm>
//#include<cmath>
//#include<cstring>
//#include<vector>
//#include<string>
//#include<queue>
//using namespace std;
//typedef long long ll;
//const int N=5e5+5,M=505;
//ll a[M][N],t[M][N],w[N];
//int k[M],c,n,m,d,q,x,y;
//int main(){
////	freopen(".in","r",stdin);
////	freopen(".out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
//	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++) cin>>w[i];
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++){
//			cin>>a[i][j]>>t[i][j];
//			vis[a[i][j]][i]=true;
//		}
//	}
//	return 0;
//}

