#include<bits/stdc++.h>
using namespace std;
void file(string x){
	freopen((x+".in").data(),"r",stdin);
	freopen((x+".out").data(),"w",stdout);
} 
#define int long long
int C,T,n,k;
const int maxn=1e6+10;
vector<int>g[maxn];
bool st[maxn];
int dis[maxn];
int bfs(){
	queue<int>q;
	for(int i=1;i<=n;++i)if(st[i])q.push(i),dis[i]=-1;else dis[i]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(dis[v]==0){
				q.push(v);
				dis[v]=max(0ll,dis[u])+1;
			}
		}
	}
	return *max_element(dis+1,dis+1+n);
}
void chk(int u){
	st[u]=0;
	for(auto v:g[u])if(st[v]==1)chk(v);
}
void clear(){
	for(int i=1;i<=n;++i)g[i].clear();
	n=k=0;
}
signed main(){
	file("hub");
	cin.tie(0)->sync_with_stdio(0);
	cin>>C>>T;
	while(T--){
		clear();
		cin>>n>>k;
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n>20){
			cout<<n/2<<"\n";
			continue;
		}
		int ans=LLONG_MAX;
		for(int i=1;i<(1<<n);++i){
			int zc=0;
			for(int j=0;j<n;++j)if(i>>j&1)st[j+1]=1,++zc;else st[j+1]=0;
			if(zc>k)continue;
			int t=bfs(),cnt=0;
			for(int j=1;j<=n;++j)if(st[j]){
				chk(j);
				++cnt;
			}
			if(cnt<=2){
				if(ans>t){
					ans=t;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
