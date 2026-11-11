#include <bits/stdc++.h>
#define int long long
#define inf INT_MAX
using namespace std;
const int N=505,M=5e5+5,D=20;//505 subway 20 dot 5e5+5 station
struct node{
	int to,nxt;
}edge[N*D];
int head[M],tot;
inline void add(int u,int v){
	edge[++tot]=(node){v,head[u]};
	head[u]=tot;
}
int c,n,m,d,q,ans;
int w[M];
int id[M][N];
inline int check(int x,int y){
	for(int i=1;i<=n;++i){
		if(id[x][i] and id[y][i]){
			return i;
		}
	}	
	return 0;
}
inline void dfs(int u,int t,int len,int tmp){
	//printf("%lld %lld %lld %lld\n",u,t,len,tmp);
	if(u==t){
		int sub=check(tmp,u),d=id[tmp][sub]+id[u][sub];
		ans=min(ans,len+d);
		//printf("111");
		return ;	
	}
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(check(v,tmp)==check(u,v)){
			dfs(v,t,len,tmp);
		}else{
			int sub=check(tmp,u),d=id[tmp][sub]+id[u][sub];
			dfs(v,t,len+d,u);
		}
	}
}
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0' or ch>'9') ch=getchar();
	while(ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	//scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		w[i]=read();
		//scanf("%lld",&w[i]);
	}
	for(int i=1,k;i<=n;++i){
		k=read();
		//scanf("%lld",&k);
		int last_u;
		for(int j=1,u,d;j<=k;++j){
			u=read(),d=read();
			//scanf("%lld %lld",&u,&d);
			id[u][i]=d;
			if(j==1){
				last_u=u;
				continue;
			}
			add(last_u,u);
			last_u=u;
		}
	}
	for(int i=1,s,t;i<=q;++i){
		s=read(),t=read();
		//scanf("%lld %lld",&s,&t);
		ans=inf;
		dfs(s,t,0,s);
		if(s==t) ans=0;
		printf("%lld\n",ans+w[s]+w[t]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
