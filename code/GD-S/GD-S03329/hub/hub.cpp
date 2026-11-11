#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int c,n,K,U[MAXN],V[MAXN];
vector<pair<int,int>>G[MAXN];
int dis[MAXN],cnt[MAXN];
int dfn[MAXN],out[MAXN],rid[MAXN],dfncnt,dep[MAXN];
void dfs(int u,int fa1){
	dfn[u]=++dfncnt,rid[dfncnt]=u;
	dep[u]=dep[fa1]+1;
	for(auto [v,id]:G[u])if(v!=fa1)dfs(v,u);
	out[u]=dfncnt;
}
int f[MAXN],g[MAXN],ban;
void dfs2(int u,int fa1){
	f[u]=0;
	for(auto [v,id]:G[u])if(v!=fa1&&ban!=id){
		dfs2(v,u),f[u]=max(f[u],f[v]+1);
	}
}
int lft[MAXN],rgt[MAXN];
void dfs3(int u,int fa1){
	vector<int>son;
	for(auto [v,id]:G[u])if(v!=fa1&&ban!=id){
		son.push_back(v);
	}
	for(int i=0;i<son.size();i++)lft[i]=rgt[i]=f[son[i]];
	for(int i=1;i<son.size();i++)lft[i]=max(lft[i],lft[i-1]);
	for(int i=(int)son.size()-2;i>=0;i--)rgt[i]=max(rgt[i],rgt[i+1]);
	for(int i=0;i<son.size();i++){
		int nw=g[u]+1,v=son[i];
		if(i)nw=max(nw,lft[i-1]+2);
		if(i+1<son.size())nw=max(nw,rgt[i+1]+2);
		g[v]=nw;
	}
	for(int v:son)dfs3(v,u);
}
int tim,lim;
int dfs4(int u,int fa1){
	int cnt=(f[u]>=lim);
	for(auto [v,id]:G[u])if(v!=fa1&&ban!=id){
		cnt+=dfs4(v,u);
	}
	if(g[u]<=lim){
		tim=min(tim,max<int>(1,cnt));
	}
	return cnt;
}
inline int get(int d,int mid){
	int X=U[d],Y=V[d],res=0;lim=mid;
	tim=n;int tt=dfs4(X,0);res+=tim;
	tim=n;int rr=dfs4(Y,0);res+=tim;
	return res;
}
mt19937 rnd(time(0));
int rd[MAXN];
inline void solve(){
	cin>>n>>K;
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;U[i]=u,V[i]=v;
		G[u].push_back({v,i});
		G[v].push_back({u,i});
	}
	dfncnt=0;dfs(1,0);
	for(int i=1;i<n;i++)if(dep[U[i]]>dep[V[i]])swap(U[i],V[i]);
	for(int i=1;i<n;i++)rd[i]=i;
	shuffle(rd+1,rd+n,rnd);
	int ans=n;
	if(c<=10){
		for(int dd=1,d=rd[1];dd<=n-1;d=rd[++dd]){
			int l=0,r=ans,res=n+1;
			ban=d;
			dfs2(U[d],0),dfs2(V[d],0);
			g[U[d]]=g[V[d]]=0;
			dfs3(U[d],0),dfs3(V[d],0);
			while(l<=r){
				int mid=l+r>>1;
				if(get(d,mid)<=K)res=mid,r=mid-1;
				else l=mid+1;
			}
			ans=min(ans,res);
		}
	}else{
		for(int dd=1,d=rd[1];dd<n&&dd<=100;d=rd[++dd]){
			int l=0,r=ans,res=n+1;
			ban=d;
			dfs2(U[d],0),dfs2(V[d],0);
			g[U[d]]=g[V[d]]=0;
			dfs3(U[d],0),dfs3(V[d],0);
			while(l<=r){
				int mid=l+r>>1;
				if(get(d,mid)<=K)res=mid,r=mid-1;
				else l=mid+1;
			}
			ans=min(ans,res);
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	int T;cin>>c>>T;while(T--)solve();
}