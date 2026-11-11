#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int INF=1e18;
int c,T,n,k,u,v,ans;
int dep[N],dis[N],tmp[N];
struct edge{
	int v,nx;
}e[N<<1];
int cnt,head[N],fa[N];
int s[N],dp[N];
void addEdge(int u,int v){
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
void dfs(int p,int ls/*,bool flag=1*/){
//	if(flag){
		fa[p]=ls;
//	}
	dep[p]=dep[ls]+1;
	for(int i=head[p];i;i=e[i].nx){
		int v=e[i].v;
		if(v!=ls){
			dfs(v,p/*,flag*/);
		}
	}
}
int find(int x){
	if(x==dp[x]){
		return x;
	}
	return dp[x]=find(dp[x]);
}
void add(int x,int y){
	int xx=find(x);
	int yy=find(y);
	if(xx!=yy){
		dp[xx]==yy;
	}
}
int bfs(int x){
	queue<pair<int,int> > q;
	q.push({x,0});
	while(!q.empty()){
		pair<int,int> t=q.front();
		if(s[t.first]){
			return t.second;
		}else{
			for(int i=head[t.first];i;i=e[i].nx){
				q.push({e[i].v,t.second+1});
			}
		}
	}
}
int calc(int mask){
	for(int i=1;i<=n;i++){
		if(mask&(1<<i-1)){
			s[i]=1;
		}else{
			s[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=e[j].nx){
			if(s[i]&&s[e[j].v]){
				add(i,e[j].v);
			}
		}
	}
	int cnt=0,p[4];
	for(int i=1;i<=n;i++){
		if(s[i]){
			if(cnt==0){
				p[++cnt]=find(i);
			}else if(cnt==1){
				if(find(i)!=p[cnt]){
					p[++cnt]=find(i);
				}
			}else{
				if(find(i)!=p[1]&&find(i)!=p[2]){
					return INF;
				}
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,bfs(i));
	}
	return res;
}
void solve(){
	cnt=0;
	ans=INF;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
	for(int i=1;i<n;i++){
		cin>>u>>v;
		addEdge(u,v);
		addEdge(v,u);
	}
	dfs(1,0);
	for(int mask=0;mask<(1<<n);mask++){
		if(__builtin_popcount(mask)>k){
			continue;
		}
		ans=min(ans,calc(mask));
	}
	cout<<ans<<'\n';
//	for(int i=0;i<(1<<n);i++){
//		ans=min(ans,calc(i));
//	}
//	u=1;
//	for(int i=2;i<=n;i++){
//		if(dep[i]>dep[u]){
//			u=i;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		dis[i]=dep[i];
//	}
//	dfs(u,0,0);
//	v=1;
//	for(int i=2;i<=n;i++){
//		if(dep[i]>dep[v]){
//			v=i;
//		}
//	}
//	if(dis[v]<dis[u]){
//		swap(u,v);
//	}
//	cout<<u<<" "<<v<<'\n';
//	while(fa[v]&&v!=u){
//		s[++tot]=v;
//		v=fa[v];
////		cout<<v<<'\n';
//	}
//	if(v==u){
//		s[++tot]=u;
//	}else{
//		int sum=0;
//		while(u){
//			tmp[++sum]=u;
//			u=fa[u];
//		}
//		for(int i=sum-1;i>=1;i--){
//			s[++tot]=tmp[i];
//		}
//	}
////	cout<<tot<<'\n';
//	if(k==2){
//		cout<<(tot+2)/4<<'\n';
//	}
//	int l=0,r=n-1;
//	while(l<r){
//		int mid=l+r>>1;
//		if(judge(mid)){
//			r=mid;
//		}else{
//			l=mid+1;
//		}
//	}
//	cout<<l<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
