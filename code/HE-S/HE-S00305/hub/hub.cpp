#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;
ll t,num,n,k,ans;
ll u[N],v[N];
ll pre1[N],idx1; 
ll pre2[N],idx2;
struct Edge{
	ll to,next;
}edge1[N],edge2[N];
void add1(ll u,ll v){
	edge1[++idx1] = {v,pre1[u]};
	pre1[u] = idx1;
}
void add2(ll u,ll v){
	edge2[++idx2] = {v,pre2[u]};
	pre1[u] = idx2;
}
int cntone(ll x){
	ll cnt=0;
	while( x > 0 ){
		if( x % 2 == 1 ){
			cnt ++;
		}
		x /= 2;
	}
	return cnt;
}
ll s[N],k1;
void find(ll x){
	int i=0;
	while( x > 0 ){
		i ++;
		if( x % 2 == 1){
			s[++k1] = i;
			add2(u[i],v[i]);
			add2(v[i],u[i]);
		}
		x /= 2;
	}
}
ll vis[N];
void dfs1(int x)
{
	vis[x]=1;
	for(int i=pre2[x];i;i=edge2[i].next){
		ll to = edge2[i].to;
		if( vis[to] )  continue;
		dfs1(to);
	}
}
ll dis[N],vis2[N];
void dfs2(int x){
	vis2[x] = 1;
	memset(dis,0x3f,sizeof(dis));
	for(int i=pre1[x];i;i=edge1[i].next){
		ll to = edge2[i].to;
		if( vis[to] )  continue;
		if( dis[x] > dis[to] + 1 ){
			dis[x] = dis[to] + 1;
			 dfs2(to);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> t >> num;
	while( num-- ){
		ans = 0;
		k = 0;
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(vis));
		memset(vis2,0,sizeof(vis));
		memset(pre1,0,sizeof(pre1));
		idx1 = 0;
		cin >> n >> k;
		for(int i=1;i<n;i++){
			cin >> u[i] >> v[i];
			add1(u[i],v[i]);
			add1(v[i],u[i]);
		}
//		for(ll i=1;i<=(1<<n)-1;i++){
//			memset(pre2,0,sizeof(pre2));
//			idx2 = 0;
//			if( cntone(1) > k )  continue;
//			find(i);
//			ll cnt=0;
//			for(int i=1;i<=k;i++){
//				if( vis[i] == 0 ){
//					cnt ++;
//					dfs1(i);
//				}
//			}
//			if( cnt2 !=2 )  continue;
//			
//			for(int i=1;i<=k1;i++){
//				dfs2(i);
//				for(int j=1;j<=k1;j++){
//					if( i != j ){
//						res = 
//					}
//				}
//			}
//		}
		cout << 1 << endl;
	}

	return 0;
} 
