#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ri=505,ru=2e5+5;//ri 线路数，ru 车站数 
set<int> zh[ru];
int opt,k,n,m,d,q,l,r,w[ru];
ll t[ri][ru];
int id[ri][ru];
ll dis[ri][ri];
ll dd[ri][ri];
int head[ri],tot,vis[ri];
struct node{
	int nxt,to,val;
}e[ru];

void add(int u,int v,int w){
	e[++tot]={head[u],v,w};
	head[u]=tot;
}

struct rp{
	ll u,val;
	bool operator<(const rp &x)const{
		return val>x.val;
	}
};

void dijkstra(int s){
	priority_queue<rp> q;
	for(int i=1;i<=n;i++) vis[i]=0,dis[s][i]=1e18;
	q.push({s,0});
	dis[s][s]=0; 
	while(q.size()){
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].val;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v]});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&opt,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,idd;j<=k;j++){
			scanf("%d%d",&idd,&t[i][j]);
			zh[idd].insert(i);
			id[i][idd]=j;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dd[i][j]=0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		if(zh[i].size()>=2){
			for(int j:zh[i]){
				for(int k:zh[i]){
					if(j==k) continue;
					dd[j][k]=dd[k][j]=min(dd[j][k],t[j][id[j][i]]+t[k][id[k][i]]);
//					add(j,k,t[j][id[j][i]]+t[k][id[k][i]]);
//					add(k,j,t[j][id[j][i]]+t[k][id[k][i]]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) 
	    for(int j=1;j<=n;j++) 
		    if(i!=j&&dd[i][j]!=0x3f3f3f3f) add(i,j,dd[i][j]);
	for(int i=1;i<=n;i++) dijkstra(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}cout<<endl;
//	}
	while(q--){
		scanf("%d%d",&l,&r);
		ll res=1e18;
		for(int i:zh[l]){
			for(int j:zh[r]){
				if(i==j){
					res=min(res,t[i][id[i][l]]+t[j][id[j][r]]);
				}else{
					res=min(res,dis[i][j]+t[i][id[i][l]]+t[j][id[j][r]]);
				}
			}
		}
		printf("%lld\n",w[l]+w[r]+res);
	}
	return 0;
} 
/*
样例六死活跑不过去，炸完了，给我40分以上吧，QAQ 
*/
