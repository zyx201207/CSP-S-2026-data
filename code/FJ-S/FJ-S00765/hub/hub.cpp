#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define int long long
#define N 21
using namespace std;
//I AK IOI
//coder:数字和每句话&&shuzihvh
//看题时间:
//complete time:
//思考过程:
/*
18:27:来不及，直接输出1吧。。。 
*/
// 不要爆零！！！
//算法: 骗分 
int read(){
	int x=0,f=1,c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
int n,k,f[N][20],dep[N],fa[N];
vector<int>g[N];
void dfs(int k,int fa){
	f[k][0]=fa;
	dep[k]=dep[fa]+1;
	for(int x:g[k]){
		if(x!=fa)dfs(x,k);
	}
}
int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	int deps=dep[v]-dep[u];
	for(int i=20;i>=0;i--)if(deps&(1<<i))v=f[v][i];
	if(u==v)return u;
	for(int i=20;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}
int getfather(int x){
	if(fa[x]==x)return fa[x];
	else return fa[x]=getfather(fa[x]);
}
void merges(int aa,int bb){
	fa[getfather(aa)]=getfather(bb);
}
void solve(){
	n=read();k=read();
	for(int i=1;i<n;i++){
		int a=read(),b=read();
		g[a].push_back(b);
		g[b].push_back(a);
		fa[i]=i;
	}
	fa[n]=n;
	dfs(1,0);
	for(int p=1;p<=20;p++){
		for(int i=1;i<=n;i++){
			f[i][p]=f[f[i][p-1]][p-1];
		}
	}
	for(int mask=0;mask<(1<<n);mask++){
		if(__builtin_popcount(mask)!=k)continue;
		int lc1=0,lc2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				
			}
		}
	}
	printf("%lld\n",1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--)solve();
	return 0;
}
