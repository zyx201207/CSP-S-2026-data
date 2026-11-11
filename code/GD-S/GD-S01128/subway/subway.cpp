#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+5;
int c,n,m,d,Q;
int w[M],a[505][505],t[M][505],l,r,pos;
ll dis[M];
bool vis[M];
struct Node{
	int s,v;
};
struct Edge{
	int id,s;
	ll d;
	bool operator<(const Edge &other)const{
	    return d>other.d;
	}
};
vector<Node>e[105];
priority_queue<Edge>q;
void dij(int st,int ed){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[st]=w[st];
	q.push({st,0,dis[st]});
	while(!q.empty()){
		int cur=q.top().id,p=q.top().s;
		q.pop();
		if(vis[cur])continue;
		vis[cur]=true;
		for(auto i:e[cur]){
			int s=i.s,v=i.v;
			ll val;
			if(s==p)val=0;
			else if(cur==st){
				val=t[cur][s];
			}
			else val=(ll)t[cur][p]+t[cur][s];
			//printf("A:%d %d p:%d s:%d %lld\n",cur,v,p,s,val);
			if(dis[v]>dis[cur]+val){
				if(v==ed)pos=s;
				dis[v]=dis[cur]+val;
				q.push({v,s,dis[v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int tt;
			scanf("%d%d",&a[i][j],&tt);
			t[a[i][j]][i]=tt;
			if(j>1){
				e[a[i][j-1]].push_back({i,a[i][j]});
				e[a[i][j]].push_back({i,a[i][j-1]});
			}
		}
	}
	//printf("T:\n");

	while(Q--){
		scanf("%d%d",&l,&r);
		dij(l,r);
		dis[r]+=(ll)w[r]+t[r][pos];
		printf("%lld\n",dis[r]);
	}
	return 0;
}
