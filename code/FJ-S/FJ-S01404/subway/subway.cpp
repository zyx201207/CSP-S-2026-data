#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int M=2e4+10;
const int N=60;
int c,n,m,d,q;
int w[M];//地铁口到站厅的时间 
//n 地铁站线路数
//m 地铁站数
//d 每个地铁站最多被几条线路穿越
//q 出行路线数 
int a[N][M],t[N][M];
int k[N];
bool f=true;
struct node{int lu,i,j;};
vector<node> e[N];
pi as[N];
int x,y;
int mi=0x3f3f3f3f;
void dfs(int u,int kk,node nxt,int cnt){
	if(u==y){
		mi=min(mi,t[nxt.i][nxt.j]+cnt);
		return;
	}
	if(u==x){
		for(int i=1;i<=n;i++){
			for(int j=1;j<k[i];j++){
				if(u==a[i][j]){
					dfs(a[i][j+1],i,{0,i,j},t[i][j]);
				}
			}
		}
	}
	if(e[u].size()==0) return;
	for(auto f:e[u]){
		int v=f.lu;
		int w=f.i;
		if(w!=kk) dfs(v,w,f,cnt+t[nxt.i][nxt.j]+t[f.i][f.j]);
		else dfs(v,w,f,cnt);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			if(j!=1) e[a[i][j-1]].push_back({a[i][j],i,j}); 
		}
	}
	while(q--){
		cin >> x >> y;
		mi=0x3f3f3f3f;
		dfs(x,0,{0,0,0},0);
		cout << mi+w[x]+w[y] << '\n';
	}
}
