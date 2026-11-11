#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f;
int c,m,n,d,q;
ll w[N],G[1010][1010];
bool ab[1010][1010];
struct node{
	int to;
	ll cst;
};
void fri(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9') x=x*10+c-'0',c=getchar();
}
void frl(ll &x){
	x=0ll;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9') x=x*10+c-'0',c=getchar();
}
vector<node> occ[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fri(c),fri(n),fri(m),fri(d),fri(q);
	for(int i=1;i<=m;i++) frl(w[i]);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  if(i!=j) G[i][j]=INF;
	for(int i=1;i<=n;i++){
		int k; fri(k);
		while(k--){
			int a; ll t;
			fri(a),frl(t);
			for(int j=0;j<occ[a].size();j++){
				int v=occ[a][j].to,cc=occ[a][j].cst;
				G[i][v]=G[v][i]=min(G[i][v],cc+t);
			}
			node tmp; tmp.to=i,tmp.cst=t;
			occ[a].push_back(tmp);
		}
	}
	for(int k=1;k<=n;k++)
	 for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	   G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	while(q--){
		int x,y;
		fri(x),fri(y);
		ll ans=INF;
		for(int i=0;i<occ[x].size();i++)
		 for(int j=0;j<occ[y].size();j++)
		  ans=min(ans,occ[x][i].cst+occ[y][j].cst+G[occ[x][i].to][occ[y][j].to]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
