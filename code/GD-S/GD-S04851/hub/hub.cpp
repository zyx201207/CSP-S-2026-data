#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,s,l,r,mx,ans,a[1000005],q[1000005],bz[1000005],bb[1000005],pre[1000005],f[4005][4005];
vector<int>g[1000005],G[1000005];
struct node{int x,y;}A[1000005];
int find(int d){
	if(pre[d]==d) return d;
	return pre[d]=find(pre[d]);
}
void bfs(int d){
	for(int i=1;i<=n;i++) f[d][i]=-1;
	l=r=1,q[1]=d,f[d][d]=0;
	while(l<=r){
		for(auto i:g[q[l]]){
			if(f[d][i]>=0) continue;
			f[d][i]=f[d][q[l]]+1,q[++r]=i;
		}
		l++;
	}
}
void dfs(int d){
	if(d>m){
		mx=s=0;
		for(int i=1;i<=n;i++) bb[i]=0,pre[i]=i;
		for(int i=1;i<n;i++){
			if(!bz[A[i].x]||!bz[A[i].y]) continue;
			int u=find(A[i].x),v=find(A[i].y);
			if(u!=v) pre[u]=v;
		}
		for(int i=1;i<=n;i++){
			if(!bz[i]) continue;
			int u=find(i);
			if(!bb[u]) bb[u]=1,s++;
		}
		if(s>2) return;
		for(int i=1;i<=n;i++){
			if(bz[i]) continue;
			int mn=1e9;
			for(int j=1;j<=n;j++){
				if(!bz[j]) continue;
				mn=min(mn,f[i][j]);
			}
			mx=max(mx,mn);
		}
		ans=min(ans,mx);return;
	}
	for(int i=1;i<=n;i++){
		if(bz[i]) continue;
		bz[i]=1,dfs(d+1),bz[i]=0;
	}
}
void wk(){
	cin>>n>>m,ans=1e9;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
		cin>>A[i].x>>A[i].y,
		g[A[i].x].push_back(A[i].y),
		g[A[i].y].push_back(A[i].x);
	if(c==13||c==14){
		if(m==n){cout<<"0\n";return;}
		if(m>=n/2){cout<<"1\n";return;}
		int t=n/2+1-m;
		for(int i=0;i<=t;i++){
			int u=t-i,x=0,y=0;
			if(u&1) x=u/2,y=x+1;
			else x=y=u/2;
			ans=min(ans,max({(i+1)/2+1,x+1,y}));
		}
		cout<<ans<<"\n";return;
	}
	for(int i=1;i<=n;i++) bfs(i);
	dfs(1),cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;
	while(T--) wk();
	return 0;
}
