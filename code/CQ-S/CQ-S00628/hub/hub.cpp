#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=15;
int n,c,t,k,T;
basic_string<int> g[N];

inline int read(){
	int x=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*t;
}

int dep[N],fa[N][32];
void dfs(int u,int f){
	fa[u][0]=f;dep[u]=dep[f]+1;
	for(int i=1;(1<<i)<=dep[u];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=T;i>=0;i--)
		if(dep[v]+(1<<i)<=dep[u])
			u=fa[u][i];
	if(u==v)return u;
	for(int i=T;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

int ans;
bitset<N> usd;
void calc(int tex){
//	for(int i=1;i<=n;i++)
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	if(c>3)return 0;
	while(t--){
		n=read();k=read();T=log2(n);
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			g[u]+=v;g[v]+=u;
		}
		dfs(1,0);
		int tot=(1<<n)-1;
		for(int i=0;i<=tot;i++){
			calc(i);
		}
		printf("%d\n",ans);
		
		for(int i=1;i<=n;i++)if(g[i].size())g[i].clear();
		ans=0;
	}

	return 0;
}
// TOOOOOOOOOOOOOO DIFFICULT...... 
// BUT LOOK AT THE TIME!!! 
// 7min left...
// -DEAD END- 
// T3、T4爆难有感觉吗
// 我觉得正常题目就不会突然在T3、T4上强度......
// 感觉他们又250+了怎么办......
//  
