#include <bits/stdc++.h>
using namespace std;
struct sub{
	long long a,t;
}su[505][500005];
struct nod{
	int v,p,u_s,v_s;
};
int c,n,m,d,q,k,vis[500005];
long long w[500005],ans = 1e15;
vector<nod> e[505];

void dfs(int S,int T,int u,long long time,int price){
	if(u == T){
		if(time+w[S]+w[T]<ans) ans = time+w[S]+w[T];
		return;
	} 
	for(int i = 0;i<e[u].size();i++){
		int v = e[u][i].v;
		int p = e[u][i].p;
		int u_s= e[u][i].u_s;
		int v_s = e[u][i].v_s;
		if(!vis[v]){
			vis[v] = 1;
			if(price!=p){
				dfs(S,T,v,time+su[price][u_s].t+su[p][v_s].t,p);
			}
			else{
				dfs(S,T,v,time,price);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[m];
	for(int i=1;i<=n;i++){
		cin>>k;
		e[i].resize(k+1);
		for(int j = 1;j<=k;j++){
			cin>>su[i][j].a>>su[i][j].t;
			if(j!=1){
				//e[su[i][j-1].a].push_back({su[i][j-1].a,i,j-1,j});
				e[su[i][j-1].a][j].v = su[i][j].a;
				e[su[i][j-1].a][j].p = i;
				e[su[i][j-1].a][j].u_s = j-1;
				e[su[i][j-1].a][j].v_s = j;
				//e[1].push_back({0,0});
			} 
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		ans = 1e15;
		cin>>x>>y;
		for(int i = 0;i<e[x].size();i++){
			int p = e[x][i].p;
			dfs(x,y,x,0,p);
		}
		//cout<<ans<<"\n";	
	}
}
