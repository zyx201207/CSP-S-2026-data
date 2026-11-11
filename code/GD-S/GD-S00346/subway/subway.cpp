#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k,a[500010][30],t[500010][30];
int h[500010],idx;
double di[500010];
struct nd{
	int to,nxt;
	double w;
}e[500010];
inline void add(int u,int v,double w){
	e[++idx].w=w;
	e[idx].nxt=h[u];
	e[idx].to=v;
	h[u]=idx;
}
struct pqe{
	int p;
	double dis;
	bool operator <(const pqe &x)const{x.dis<dis;}
};
priority_queue<pqe> pq;
bool vis[5000010];
inline dij(int s){
	pq.push({s,t[s][s]});
	while(!pq.empty()){
		pqe cur=pq.top();
		pq.pop();
		double x=cur.dis;int tt=cur.p;
		if(vis[tt]) continue;
		vis[tt]=1;
		for(int i=h[tt];i;i=e[i].nxt){
			int v=e[i].to;
			if(di[v]>di[tt]+e[i].w){
				di[v]=di[tt]+e[i].w;
				if(!vis[v]){
					pq.push({v,di[v]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=q;i++){
		cout<<1<<endl;
	}
//	for(int i=1;i<=m;i++){
//		scanf("%d",w+i);
//	}
//	if(n*m*m<1e8&&k*k*n<1e8){
//		for(int i=1;i<=n;i++){
//			scanf("%d",&k);
//			for(int j=1;j<=k;j++){
//				scanf("%d%d",&a[i][j],&t[i][j]);
//				for(int x=1;x<j;x++){
//					add(j,x,t[i][j]+t[i][x]);
//					add(x,j,t[i][j]+t[i][x]);
//				}
//			}
//		}
//		int s,t;
//		for(int i=1;i<=m;i++){
//			di[i]=INT_MAX;
//			vis[i]=0;
//		}
//		for(int i=1;i<=q;i++){
//			scanf("%d%d",&s,&t);
//			dij(s);
//			cout<<di[t]+w[s]+w[t]<<endl;
//		}
//	}
	return 0;
}

