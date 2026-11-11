#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2000005;
int c,t,n,k,fa[N],v[N],dis[N];
vector<int>g[N];
int query(int x){
	if(fa[x]==x)return x;
	return fa[x]=query(fa[x]);
}
inline void add(int x,int y){
	fa[query(x)]=query(y);
}
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int r=0x3f3f3f3f3f3f3f3f;
	for(int S=0;S<(1ll<<n);S++){
		if(__builtin_popcountll(S)==k){
			for(int i=1;i<=n;i++)fa[i]=i,v[i]=0;
			for(int i=1;i<=n;i++){
				if(S&(1ll<<i-1)){
					for(auto j:g[i]){
						if(S&(1ll<<j-1))add(i,j);
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(S&(1ll<<i-1)){
					v[query(i)]=1;
				}
			}
			int s=0;
			for(int i=1;i<=n;i++){
				if(S&(1ll<<i-1)){
					s+=v[i];
				}
			}
			if(s>2)continue;
			queue<int>q;
			for(int i=1;i<=n;i++){
				if(S&(1ll<<i-1)){
					q.push(i);
					dis[i]=0;
				}else dis[i]=0x3f3f3f3f3f3f3f3f;
			}
			while(!q.empty()){
				int top=q.front();
				q.pop();
				for(auto j:g[top]){
					if(dis[j]==0x3f3f3f3f3f3f3f3f){
						dis[j]=dis[top]+1;
						q.push(j);
					}
				}
			}
			int dd=0;
			for(int i=1;i<=n;i++)dd=max(dd,dis[i]);
			r=min(r,dd);
		}
	}
	cout<<r<<'\n';
}
signed main(){
#ifndef XYZ
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c<=3){
		while(t--)solve();
	}
	return 0;
}

