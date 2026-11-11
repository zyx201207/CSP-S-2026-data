#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+10;
const ll INF = LONG_LONG_MAX;
struct edge{
	ll ed,nxt;
}b[N];
ll nbs[N],tot;
void addedge(ll x,ll y){
	b[++tot].ed = y;
	b[tot].nxt = nbs[x];
	nbs[x] = tot;
	return ;
}
ll n,k,c,T;
ll d[N];
ll f[N][30];
ll f2[N];
ll vis[N];
ll dep[N];
ll ans=INF;
//Lca
void dfs(ll u,ll fa){
	f[u][0] = fa;
	dep[u] = dep[fa]+1;
	for(ll i=1;i<=25;i++){
		f[u][i] = f[f[u][i-1]][i-1];
	}
	for(ll i=nbs[u];i;i=b[i].nxt){
		ll v = b[i].ed;
		if(v==fa){
			continue;
		}
		dfs(v,u);
	}
	return ;
} 
ll Lca(ll x,ll y){
	if(dep[y]<dep[x]) swap(x,y);
	for(ll i=25;i>=0;i--){
		if(dep[f[y][i]]>=dep[x]){
			y = f[y][i];
		}
	}
	if(x==y){
		return x;
	}
	for(ll i=25;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
ll dis(ll x,ll y){
	return dep[x]+dep[y]-2*dep[Lca(x,y)];
}
ll find(ll x){
	if(f2[x]==x) return x;
	else return f2[x] = find(f2[x]);
}
void merge(ll x,ll y){
	ll fx = find(x);
	ll fy = find(y);
	if(fx==fy){
		return ;
	}	
	f2[fx] = fy;
	return ;
}
void dfs1(ll x){
	if(x>k){
		//我们先检查一下当前是否只有两个连通块
		//用并查集来判定 
		for(ll i=1;i<=n;i++){
			f2[i] = i;
		}
		for(ll i=1;i<=n;i++){
			if(vis[i]==1){
				for(ll j=1;j<=n;j++){
					if(vis[j]==1){
						if(dis(i,j)==1)
							merge(i,j);
					} 
				}
			}
		}
		ll tmpn = 0;
		for(ll i=1;i<=n;i++){
			if(vis[i]==1&&f2[i]==i){
				tmpn++;
			}
		}
		if(tmpn>2) return ;
		//我们开始得出此时的半径长度
		ll ret = 0;
		for(ll i=1;i<=n;i++){
			ll tmp = INF;
			for(ll j=1;j<=n;j++){
				if(vis[j]==1){
					tmp = min(tmp,dis(i,j));
				}
			}
			ret = max(ret,tmp);
		}
		ans = min(ans,ret);
		return ;
	}
	for(ll i=d[x-1]+1;i<=n;i++){
		d[x] = i;
		vis[i] = 1;
		dfs1(x+1);
		vis[i] = 0;
		d[x] = 0;
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		tot = 0;
		for(ll i=1;i<=n;i++) nbs[i] = 0;
		for(ll i=1;i<=n;i++){
			for(ll j=0;j<=25;j++){
				f[i][j] = 0; 
			}
		}
		ans = INF;
		for(ll i=1,x,y;i<=n-1;i++){
			cin>>x>>y;
			addedge(x,y);
			addedge(y,x);
		}
		//做Lca 
		dfs(1,0);
//		cout<<Lca(1,2)<<" "<<dis(10,5)<<endl;
//		cout<<Lca(2,3)<<" "<<dis(8,6)<<endl;
//		cout<<Lca(1,4)<<" "<<dis(3,9)<<endl;
//		cout<<"!"<<endl;
		if(n<=100){
			dfs1(1);
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
首先 直接暴力 
然后 我们考察那个特殊性质 我们发现对于这一个方案而言 
我们从中间的点开始一次向外面选
也就是 从m/2的位置
下一次选m/2+1
下一次选m/2-1
下一次选m/2+1+1
下一次选m/2-1-1
这样子肯定是最优的
 
 
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
