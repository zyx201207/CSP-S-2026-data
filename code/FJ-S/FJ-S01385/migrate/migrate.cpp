#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,M=5005;
int c,q,n,d,x[N],f[M][M];
int g[M][M],s=0;
struct node{
	int to,next,val;
}e[N];
int head[N],pos;
inline void add(int u,int v,int w){
	pos+=1;
	e[pos].next=head[u];
	e[pos].to=v;
	e[pos].val=w;
	head[u]=pos;
	return;
}
int start=0;
inline void dfs(int u,int dep){
	if(start!=u){
		if(f[start][u]==dep) g[start][u]+=1;
//		if(f[start][u]==dep){
//			g[start][u]+=1;
//			for(int i=u;i<=n;i++){
//				g[start][i]+=g[u][i];
//			}
//		}
		if(f[start][u]<dep) return;
	}
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		dfs(v,dep+1);
	}
	return;
}
inline void calc(){
	for(int i=1;i<=n;i++){
		head[i]=0,pos=0;
		for(int j=1;j<=n;j++){
			f[i][j]=0,g[i][j]=0;
		}
	}
	int tttt;
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			if(x[i]+d>=x[j]){
				f[i][j]=1;
				add(i,j,1);
				//cout << i << " " << j << " build1\n";
			}else{
				if(x[i]+d>=x[j-1]) tttt=j-1;
				if(f[tttt][j]) f[i][j]=1+f[tttt][j];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout << f[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "\n";
	//f[i][j]代表(i,j)的最小长度 
	//dfs求？ 
	for(int i=n;i>=1;i--){
		start=i;
		dfs(i,0);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout << g[i][j] << " ";
			if(g[i][j]==2) ans+=1;
		}
		//cout << "\n";
	}
	cout << ans << "\n";
	return;
}
inline void solve(){
	cin >> n >> d;
	for(int i=1;i<=n;i++) cin >> x[i];
	if(n<=6000) calc();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> q;
	while(q--) solve();
	return 0;
} 
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/
