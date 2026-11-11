#include<bits/stdc++.h>
using namespace std;
struct node{int u,s;};
struct edge{int id,ti;};
struct cmp{
	bool operator()(node a,node b){
		return a.s>b.s;
	}
};
int c,n,m,d,q,w[500005],dis[500005],v[500005];
priority_queue<node,vector<node>,cmp>p;
vector<edge>a[505];
void dist(int fiu){
	memset(dis,128,sizeof(dis));
	p.push({fiu,0});
	while(!p.empty()){
		node nxt=p.top();p.pop();
		int id=nxt.u,time=nxt.s;
		if(time>dis[id])continue;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k,g,t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&g,&t);
			a[i].push_back({g,t});
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		dist(x);
		printf("%d",w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
