#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[500003],b[500003];
int e[500003],to[500003],h[500003],cnt;
int f[21][500003],lg[500003];
int siz[500003],dis[500003],dfn[500003],top;
int ans[300003];
void dfs(const int&id){
	dfn[id]=++top;
	siz[id]=1;
	for(int i=h[id];i;i=to[i]){
		dis[e[i]]=dis[id]+1;
		dfs(e[i]);
		siz[id]+=siz[e[i]];
	}
}
bool cmp(int x,int y){
	if(a[x]!=a[y])return a[x]<a[y];
	return dfn[x]<dfn[y];
}
int lca(int x,int y){
	if(dis[x]<dis[y])swap(x,y);
	for(int i=lg[dis[x]];i>=0;i--){
		if(dis[x]-(1<<i)>=dis[y])x=f[i][x];
	}
	if(x==y)return x;
	for(int i=lg[dis[x]];i>=0;i--){
		if(f[i][x]!=f[i][y]){
			x=f[i][x];y=f[i][y];
		}
	}
	return f[0][x];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin>>n>>m;
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int j=1;j<=n;j++){
		e[++cnt]=j;
		to[cnt]=h[b[a[j]]+1];
		h[b[a[j]]+1]=cnt;
		f[0][j]=b[a[j]]+1;
	}
	dfs(n+1);
	for(int i=1;i<=lg[n];i++){
		for(int j=1;j<=n;j++)f[i][j]=f[i-1][f[i-1][j]];
	}
	for(int i=1;i<=n;i++)b[i]=i;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[b[i]]!=a[b[i-1]])ans[a[b[i]]]+=siz[b[i]];
		else{
			if(lca(b[i],b[i-1])==b[i-1])b[i]=b[i-1];
			else ans[a[b[i]]]+=siz[b[i]];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' '; 
	return 0;
}
