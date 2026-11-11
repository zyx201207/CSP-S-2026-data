#include<bits/stdc++.h>
using namespace std;
namespace my_space{
	using ll = long long;
	using exl = __int128;
	int constexpr N = 5e5+505;
	struct graph{
		int top[N],nxt[N*2],to[N*2],val[N*2],tot;
		void add(int x,int y,int v){
			nxt[++tot] = top[x];
			to[tot] = y;
			top[x] = tot;
			val[tot] = v;
		}
	}g;
	ll dis[505][505];
	int n,m;
	int w[N];
	int main(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int c,d,q;
		cin>>c>>n>>m>>d>>q;
		for(int i = 1;i<=m;i++){
			cin>>w[i];
		}
		for(int i = 1;i<=n+m;i++) g.top[i] = -1; 
		for(int i = 1;i<=n;i++){
			int k;
			cin>>k;
			for(int j = 1;j<=k;j++){
				int u,v; 
				cin>>u>>v; 
				g.add(i+m,u,v);
				g.add(u,i+m,v);
			}
		}
		memset(dis,0x3f,sizeof dis);
		for(int i = 1;i<=n;i++) dis[i][i] = 0;
		for(int i = 1;i<=m;i++){
			for(int j = g.top[i];~j;j = g.nxt[j]){
				int a = g.to[j];
				ll x = g.val[j];
				for(int k = g.top[i];~k;k = g.nxt[k]){
					int b = g.to[k];
					if(a==b) continue;
					ll y = g.val[k];
					dis[a-m][b-m] = min(x+y,dis[a-m][b-m]);
					dis[b-m][a-m] = min(x+y,dis[a-m][b-m]);
				}
			}
		}
		for(int k = 1;k<=n;k++){
			for(int i = 1;i<=n;i++){
				for(int j= 1;j<=n;j++){
					dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		} 
		for(int i = 1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			ll ans = 1e18;
			for(int j = g.top[x];~j;j = g.nxt[j]){
				int a = g.to[j];
				ll sum1 = g.val[j];
				for(int k = g.top[y];~k; k = g.nxt[k]){
					int b = g.to[k]; 
					ll sum2 = g.val[k];
					ans = min(ans,dis[a-m][b-m]+w[x]+w[y]+sum1+sum2);
				} 
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}
int main(){
	return my_space::main();
}

