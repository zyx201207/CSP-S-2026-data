#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+12;
const int SN=4004;

int T,TID;
int n,k;
int head[N],to[N<<1],nex[N<<1],tot=0;
inline void mkr(int u,int v){
	to[++tot]=v,nex[tot]=head[u],head[u]=tot;
} 


bool is[N];
bool vis[N];
void bfs(int x){
	queue<int> q;
	q.emplace(x);
	vis[x]=1;
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int f=head[now];f;f=nex[f]){
			int t=to[f];
			if(!vis[t]&&is[t]){
				vis[t]=1;
				q.emplace(t);
			}
		}
	}
}
int dis[N];
void bfs2(){
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(is[i]){
			q.emplace(i);
			vis[i]=1;dis[i]=0;
		}
	}
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int f=head[now];f;f=nex[f]){
			int t=to[f];
			if(!vis[t]){
				dis[t]=dis[now]+1;
				vis[t]=1;
				q.emplace(t);
			}
		}
	}
}

int calc(){
	int ct=0;
	for(int i=1;i<=n;++i){
		vis[i]=0;dis[i]=0x3f3f3f3f;
	}
	for(int i=1;i<=n;++i){
		if(is[i]&&!vis[i]){
			bfs(i);ct++;
		}
	}
	if(ct>2){
		return 0x3f3f3f3f;
	}
	for(int i=1;i<=n;++i){
		vis[i]=0;
	}
	bfs2();
	int mx=0;
	for(int i=1;i<=n;++i){
		mx=max(mx,dis[i]);
	}
	return mx;
}
int ans;
void dfs(int now,int ks){
	if(ks>k)return;
	if(now==n+1){
		if(ks==k)ans=min(ans,calc());
		return;
	}
//	cerr<<"PP! "<<now<<" "<<ks<<endl;
//		for(int i=1;i<=n;++i){
//			cerr<<is[i]<<" ";
//		}
//		cerr<<endl;
	is[now]=0;
	dfs(now+1,ks);
	is[now]=1;
	dfs(now+1,ks+1);
}

void Solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		mkr(u,v),mkr(v,u);
	}
	ans=0x3f3f3f3f;
	dfs(1,0);
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i){
		head[i]=0;
	}
	for(int j=1;j<=tot;++j){
		to[j]=nex[j]=0;
	}
	tot=0;
}

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>TID>>T;
	while(T--)Solve();
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
