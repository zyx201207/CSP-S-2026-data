#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int C,n,m,d,Q;
int w[500010];
int k[510];
vector<int>id[510];
map<int,ll>t[500010];
vector<int>crs[500010];
int sum[500010];
map<int,int>cont[510];
struct Edge{
	int to;
	ll l; 
	Edge(){}
	Edge(int newto,ll newl){
		to=newto;
		l=newl;
	}
};
vector<Edge>edges[1001010];

ll query(int s,int t){
	for(auto i:edges[s]){
		for(auto j:edges[t]){
			for(int K=1;K<=n;K++){
				if(cont[K][i.to]&&cont[K][j.to]){
					return i.l+j.l;
				}
			}
		}
	}
	return 0ll;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%d%d",&x,&y);
			id[i].push_back(x);
			t[x][j]=y;
		}
	}
	//m+sum[i-1]+1~m+sum[i]是i号站点的地铁口
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			crs[id[i][j]].push_back(i);
			cont[i][j]=crs[id[i][j]].size();
		}
	}
	for(int i=1;i<=m;i++){
		sum[i]=sum[i-1]+crs[i].size();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			int id1=id[i][j],id2=id[i][j-1];
			edges[m+sum[id1-1]+cont[i][j]].push_back(Edge(m+sum[id2-1]+cont[i][j-1],0));
			edges[m+sum[id2-1]+cont[i][j-1]].push_back(Edge(m+sum[id1-1]+cont[i][j],0));
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=m+sum[i-1]+1;j<=m+sum[i];j++){
			edges[i].push_back(Edge(j,t[i][j-m-sum[i-1]]));
			edges[j].push_back(Edge(j,t[i][j-m-sum[i-1]]));
		} 
	}
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=1ll*w[x]+1ll*w[y];
		ans+=query(x,y);
		printf("%lld\n",ans);
	}
	return 0;
}
