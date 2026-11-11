#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,MN=505;
const ll inf=1e18;
int c,n,m,d,Q;
ll w[N];int k[MN],vis[MN][MN];
vector<pair<int,ll> >pa[MN],v[N];
struct node{
	int k,j;ll dis;
	friend bool operator <(const node a,const node b){
		return a.dis>b.dis;
	}
};
priority_queue<node>q;
ll cst[MN][MN];
void dijk(){
	memset(cst,0x3f,sizeof(cst));
	for(int i=1;i<=n;i++)
	  cst[i][i]=0,q.push({i,i,0});
	while(!q.empty()){
		node u=q.top();q.pop();
		if(vis[u.k][u.j]) continue;
		vis[u.k][u.j]=1;
		for(pair<int,ll>tp:pa[u.k]){
			int a=tp.first,ti=tp.second;
			for(pair<int,ll>tp2:v[a]){
				int pid=tp2.first,ti2=tp2.second;
				if(cst[pid][u.j]>cst[u.k][u.j]+ti+ti2){
					cst[pid][u.j]=cst[u.k][u.j]+ti+ti2;
					q.push({pid,u.j,cst[pid][u.j]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		int x;ll ti;
		for(int j=1;j<=k[i];j++){
			scanf("%d%lld",&x,&ti);
			pa[i].push_back({x,ti});
			v[x].push_back({i,ti});
		}
	}
	dijk();
	for(int Gr=1,x,y;Gr<=Q;Gr++){
		scanf("%d%d",&x,&y);
		ll res=w[x]+w[y],ans=inf;
		for(pair<int,ll>tp:v[x])
		  for(pair<int,ll>tp2:v[y]){
		  	ll tx=tp.second,ty=tp2.second;
		  	int si=tp.first,sj=tp2.first;
		  	ans=min(ans,cst[si][sj]+tx+ty);
		  }
		res+=ans;
		printf("%lld\n",res);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
