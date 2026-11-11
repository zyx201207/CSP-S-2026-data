#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e6+5,INF=1e9;
int n,k,ans=INF,num;
bool vis[N];
vector<int>g[N];
inline void df1(int u,int fa){
	vis[u]=0;
	for(int v:g[u]){
		if(v^fa){
			if(vis[v])df1(v,u); 
		}
	}
}
inline void df2(int u,int fa,int dis){
	if(vis[u])num=min(num,dis);
	for(int v:g[u]){
		if(v^fa){
			df2(v,u,dis+1);
		}
	}
}
inline bool check(int sta){
	for(int i=1;i<=n;++i)vis[i]=((sta&(1<<(i-1)))!=0);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(vis[i]){df1(i,0);++cnt;}
		if(cnt>2)break;
	}
	return cnt<=2;
}
inline void getans(int sta){
	int tot=0;
	for(int i=1;i<=n;++i)vis[i]=((sta&(1<<(i-1)))!=0);
	for(int i=1;i<=n;++i){
		num=INF;
		if(!vis[i]){
			df2(i,0,0);
			tot=max(tot,num);
		}
	}
	ans=min(ans,tot);
} 
inline void init(){
	for(int i=1;i<=n;++i){
		g[i].clear();
		vis[i]=0;
	}
}
inline void solve(){
	init(); 
	cin>>n>>k;
	ans=INF;
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<(1<<n);++i){
		if(__builtin_popcount(i)!=k)continue;
		if(check(i))getans(i);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	} 
	return 0; 
}

//5~15pts 
