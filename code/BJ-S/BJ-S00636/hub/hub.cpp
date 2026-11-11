#include<bits/stdc++.h>
using namespace std;
int n,k,d[1000010],f[1000010][30];
vector<int>g[1000010];
void dfs(int x=1,int pre=1){
	d[x]=d[pre]+1;
	f[x][0]=pre;
	for(int i:g[x]){
		if(i==pre) continue;
		dfs(i,x);
	}
}
void ycl(){
	for(int k=1;(1<<k)<=n;k++)
		for(int i=1;i<=n;i++)
			f[i][k]=f[f[i][k-1]][k-1];
}
int lowbit(int x){return x&-x;}
int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	for(int i=d[x]-d[y];i;i-=lowbit(i)) x=f[x][(int)log2(lowbit(i))];
	if(x==y) return x;
	for(int k=log2(n);k>=0;k--)
		if(f[x][k]!=f[y][k]) x=f[x][k],y=f[y][k];
	return f[x][0];
}
int up(int x,int s){
	for(;s;s-=lowbit(s)) x=f[x][(int)log2(lowbit(s))];
	return x;
}
bool chk(int x){
	vector<int>hub;
	for(int i=1;i<=n;i++)
		if(i!=1&&g[i].size()==1)
			hub.push_back(up(i,x));
	int LCA=hub[0],sum=hub.size()+1;
	for(int i:hub) LCA=lca(LCA,i);
	for(int i:hub)
		if(i==LCA){
			sum--;
			break;
		}
	for(int i:hub){
		sum+=max(d[i]-d[LCA]-1,0);
	}
	sum+=max(0,d[LCA]-x);
	if(sum<=k) return 1;
	if(2*x<k-sum) return 0;
	for(int i:hub){
		if(max(d[i]-d[LCA]-1,0)>=k-sum) return 1;
	}
	return max(d[LCA]-x-1,0)>=k-sum;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(d,0,sizeof d);
		memset(f,0,sizeof f);
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		d[1]=-1;
		dfs();
		ycl();
		int l=0,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(chk(mid)) r=mid;
			else l=mid+1;
		}
		cout<<r<<endl;
	}
	return 0;
}
