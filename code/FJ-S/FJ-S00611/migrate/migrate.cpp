#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+10;
const ll INF = LONG_LONG_MAX;
struct edge{
	ll ed,nxt;
}b[N*2];
ll nbs[N],tot;
void addedge(ll x,ll y){
	b[++tot].ed = y;
	b[tot].nxt = nbs[x];
	nbs[x] = tot;
	return ;
}
ll c,T;
ll n,d; 
ll dis[N];
ll g[N];
ll a[N];
struct node{
	ll u,dis;
	bool operator < (const node &x) const{
		return dis<x.dis;
	}
	bool operator > (const node &x) const{
		return dis>x.dis;
	}
};
priority_queue < node,vector < node >,greater < node > > q;
void dij(ll be){
	for(ll i=1;i<=n;i++){
		dis[i] = INF;
		g[i] = 0;
	}
	dis[be] = 0;
	g[be] = 1;
	q.push({be,0});
	while(!q.empty()){
		node tmp = q.top();
		q.pop();
		ll u = tmp.u;
		for(ll i=nbs[u];i;i=b[i].nxt){
			ll v = b[i].ed;
			if(dis[v]==dis[u]+1){
				g[v] = g[v]+g[u];
			}
			else if(dis[v]>dis[u]+1){
				dis[v] = dis[u]+1;
				g[v] = g[u]; 
				q.push({v,dis[v]});
			}
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		//清空
		tot = 0;
		ll flag = 0;
		for(ll i=1;i<=n;i++) nbs[i] = 0; 
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		for(ll i=2;i<n;i++){
			if(a[i+1]-a[i]!=a[i]-a[i-1]){
				flag = 1;
			}
		}
		//我们暴力 
		if(n<=5000){
			//正常建图 
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
						addedge(i,j);
						addedge(j,i);
					}
				}
			}
			ll ans = 0;
			//然后我们做最短路计数
			for(ll i=1;i<=n;i++){
				dij(i);
				for(ll j=1;j<=n;j++){
					if(g[j]==2){
						ans++; 
					}
				}
			} 
			ans = ans/2;
			cout<<ans<<endl;
		}
		//如果说他是特殊性质1 
		else if(flag==0){
			//我们先考虑一步可以跨出几个点
			ll k = 0;
			for(ll i=2;i<=n;i++){
				if(a[i]-a[1]<=d) k++;
			} 
			//然后我们对于k进行讨论
			//如果说要么只能跨出一步 要么一步都跨不出 那么我们显然后答案只是0 
			if(k<=1){
				cout<<0<<endl;
			} 
			//不然的话 如果说他一步可以跨出很2步及以上 那么我们发现 
			//他只能跨出两大步后退回一个的位置才是可以成功配上的 
			else{
				ll ans = 0;
				for(ll i=1;i<=n;i++){
					if(i+2*k-1<=n) ans++;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
/*
建图 然后最短路计数
显然是O(n^2)
可以有一些分数

特殊性质A显然好做
特殊性质B用二分可以搜索出来
也能做 

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
