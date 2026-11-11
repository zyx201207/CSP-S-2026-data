#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define P pair<LL,int>
const int N=4e5+5;

int c,n,m,d,q;

vector<P> e[N*2];

int ztk[505],k[505];

int a[505][N],t[505][N];

LL dis[N*2];

void djs(int u){
	priority_queue<P,vector<P>,greater<P> > pq;
	dis[u]=0;
	pq.push({0,u});
	while (!pq.empty()){
		auto pp=pq.top();
		pq.pop();
		LL cost=pp.first;
		int uu=pp.second;
		for (auto myy : e[uu]){
			if (myy.first+dis[uu]>dis[myy.second]) continue;
			dis[myy.second]=myy.first+dis[uu];
			pq.push({dis[myy.second],myy.second});
		}
	}
}
int main(){
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	scanf ("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) scanf ("%d",&ztk[i]);
	for (int i=1;i<=n;i++){
		scanf ("%d",&k[i]);
		for (int j=1;j<=k[i];j++){
			scanf ("%d %d",&a[i][j],&t[i][j]);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k[i];j++){
			for (int jj=j+1;jj<=k[i];jj++){
				e[a[i][j]].push_back({t[i][j]+t[i][jj],a[i][jj]});
				e[a[i][jj]].push_back({t[i][j]+t[i][jj],a[i][j]});
			}
		}
	}
	while (q>0){
		q--;
		int x,y;
		scanf ("%d%d",&x,&y);
		fill(dis+1,dis+d*m*2+1,1e18);
		djs(x);
		printf ("%lld\n",dis[y]+ztk[x]+ztk[y]);
	}
	return 0;
}
