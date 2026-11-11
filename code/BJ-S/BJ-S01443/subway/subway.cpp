#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF=1e18;
int c,n,m,d_,q;
ll w[500005];
struct Node{
	vector<int> child;
	vector<ll> w;
}d[500505];
struct node{
	int pos;
	ll val;
};
struct Cmp{
	bool operator()(const node& x,const node& y)const{
		return x.val>y.val;//小根堆
	}
};
priority_queue<node,vector<node>,Cmp> pq;
ll dis[500505];
ll djst(int x,int goal){
	for(int i=1;i<=n+m;i++) dis[i]=INF;
	dis[x]=0;
	node t;
	t.val=0,t.pos=x;
	pq.push(t);
	while(!pq.empty()){
		node no=pq.top();
		int now=no.pos;
		pq.pop();
		if(no.val>dis[now]) continue;
		for(int i=0;i<(int)d[now].w.size();i++){
			int pos=d[now].child[i];
			if(dis[pos]>dis[now]+d[now].w[i]){
				dis[pos]=dis[now]+d[now].w[i];
				node tt;
				tt.val=dis[pos],tt.pos=pos;
				pq.push(tt);
			}
		}
	}
	return dis[goal];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d_,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		//n+i stop
		int stop,k;
		ll t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&stop,&t);
			d[m+i].child.push_back(stop);
			d[m+i].w.push_back(t);
			d[stop].child.push_back(m+i);
			d[stop].w.push_back(t);
		}
	}
	int x,y;
	while(q--){
		scanf("%d%d",&x,&y);
		if(x==y){
			printf("%d\n",0);
		}
		else{
			printf("%lld\n",djst(x,y)+w[x]+w[y]);
		}
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*//*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
