#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define int long long
int inf=2e18;
int c,T;
int d;
int n,k;
int f[N],h[N],nd[N];
int dp[N],se[N],td[N];
vector<int> g[N];
bool fl;
void add(int x,int v) {
	if(v>dp[x]) {
		td[x]=se[x];
		se[x]=dp[x];
		dp[x]=v;
	} else if(v>se[x]) {
		td[x]=se[x];
		se[x]=v;
	} else if(v>td[x]) td[x]=v;
}
int get(int x,int y,int z) {
	if(y==dp[x]) {
		if(z==se[x]) return td[x];
		else return se[x];
	} else if(y==se[x]) {
		if(z==dp[x]) return td[x];
		else return dp[x];
	} else if(y==td[x]) {
		if(z==dp[x]) return se[x];
		else return dp[x];
	}
	return 0;
}
void dfs(int x,int fa) {
	dp[x]=se[x]=td[x]=0;
	f[x]=1;
	
	int ct=0,ps=0;
	for(auto u:g[x]) {
		if(u==fa) continue;
		dfs(u,x);
		if(dp[u]>=d) f[x]+=f[u];
		
		int v=dp[u]+1;
		if(v>d) {
			ct++;
			ps=u;
		}
		
		add(x,v);
	}
	
	// h,nd
	if(!ct) {
		h[x]=0,nd[x]=1;
	} else if(ct==1) {
		int v=max(h[ps]+1+se[x]-d,0ll);
		h[x]=h[ps]+1-v;
		nd[x]=nd[ps]+v;
	} else if(ct>=2) {
		nd[x]=f[x];
		h[x]=0;
	}
	
//	cout<<x<<" "<<f[x]<<" "<<h[x]<<" "<<nd[x]<<" "<<ct<<'\n';
}
void dfs1(int x,int fa,int md,int hd,int ndd) { //mxd(Ö±½Ó d),h,nd
//	cout<<x<<" "<<nd[x]<<" "<<ndd<<" "<<md<<" "<<hd<<'\n';
	if(nd[x]+ndd<=k) {
		fl=1;
		return;
	}
	
	add(x,md);
	int ct=0,ps=0,ps2=0;
	if(md>d) ct++,ps=fa;
	for(auto u:g[x]) {
		if(u==fa) continue;
		if(dp[u]+1>d) {
			ct++;
			if(!ps) ps=u;
			else ps2=u;
		}
	}
	
	for(auto u:g[x]) {
		if(u==fa) continue;
		ct-=(dp[u]+1>d);
		int sum=dp[x]+se[x],nmd=dp[x];
		if(dp[u]+1==dp[x]) sum=se[x]+td[x],nmd=se[x];
		else if(dp[u]+1==se[x]) sum=dp[x]+td[x];
		
		if(!ct) {
//			cout<<"! ";
			dfs1(u,x,nmd+1,1,1);
		}
		else if(ct==1) {
//			cout<<"!! ";
			int az=ps,v=0;
			if(az==u) az=ps2;
				
			if(az==fa) {
//				cout<<get(x,md,dp[u]+1)<<"? ";
				v=max(hd+get(x,md,dp[u]+1)-d,0ll);
				dfs1(u,x,nmd+1,hd-v +1,ndd+v);
			} else {
				v=max(h[az]+1+get(x,dp[az]+1,dp[u]+1)-d,0ll);
				dfs1(u,x,nmd+1,h[az]+1-v +1,nd[az]+v);
			}
		} else if(ct>=2) dfs1(u,x,nmd+1,1,f[x]-f[u]*(dp[u]>=d)+(hd+ndd-1)*(md-1>=d));
		
		ct+=(dp[u]+1>d);
	}
} 
void work(int x,int fa) {
	if(fa!=0) {
		dfs(fa,x);
		fl|=(nd[x]+nd[fa]<=k);
	}
	
	for(auto u:g[x]) {
		if(u==fa) continue;
		work(u,x);
	}
}
bool check(int x) {
	d=x;
	fl=0;
	dfs(1,0);
	if(n<=4000) work(1,0);
	else dfs1(1,0,0,0,0); 
//	dfs1(1,0,0,0,0);
	return fl;
}
signed main() {
//	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=1;i<n;i++) {
			int u,v; cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		int l=0,r=n-1,ans=n-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(check(mid)) ans=mid,r=mid-1;
			else l=mid+1;
		}
//		cout<<check(2)<<'\n';
//		cout<<'\n';
		cout<<ans<<'\n';
		
		//clear
		for(int i=1;i<=n;i++) {
			g[i].clear();
		}
	}
	return 0;
} 
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9



*/
