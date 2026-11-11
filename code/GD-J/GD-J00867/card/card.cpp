#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],siz[N],lst[M],cnt[M];
vector<int> g[N];
void dfs(int u,int fa){
	siz[u]=1;
	for(int v:g[u]) if(v^fa)
		dfs(v,u),siz[u]+=siz[v];
	cnt[a[u]]+=siz[u];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",a+i),lst[a[i]]=i;
	for(int i=1;i<=n;++i) g[lst[a[i]]+1].push_back(i);
	dfs(n+1,0);
	for(int i=1;i<=m;++i) printf("%d ",cnt[i]);
	return 0;
}
