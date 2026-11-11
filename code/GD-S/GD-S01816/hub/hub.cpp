#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e6+10;
const int M=4e6+10;
const int K=15;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int c,t;
int n,k;
struct node{
	int v,nxt;
}e[M];
int head[N],tot;
inline void add(int u,int v){
	tot++;
	e[tot].v=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
int dp[4010][4010][2];
int dep[N],siz[N],fa[N],top[N];
inline void clean(){
	tot=0;
	for(int i=0;i<=n;++i){
		head[i]=0;
		for(int j=1;j<=n;++j){
			dp[i][j][0]=dp[i][j][1]=INF;
		} 
	}
}
void dfs1(int u,int f){
	fa[u]=f;
	dep[u]=dep[f]+1;
	siz[u]=1;
	for(int it=head[u];it;it=e[it].nxt){
		int v=e[it].v;
		if(f==v)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
	}
}
void dfs2(int u,int tp){
	top[u]=tp;
	int h_son=0;
	for(int it=head[u];it;it=e[it].nxt){
		int v=e[it].v;
		if(v==fa[v])continue;
		if(siz[v]>siz[h_son])h_son=v;
	}
	if(h_son==0)return;
	dfs2(h_son,tp);
	for(int it=head[u];it;it=e[it].nxt){
		int v=e[it].v;
		if(v==fa[v]||v==h_son)continue;
		dfs2(v,v);
	}
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]]; 
	}
	return (dep[u]>dep[v]?v:u);
}
int dis[4010][4010];
//int get_dis(int u){
//	int mx=0;
//	for(int it=head[u];it;it=e[it].nxt){
//		int v=e[it].v;
//		if(v==fa[u])continue;
//		int tmp=get_dis(v);
//		for(int i=1;i<=n;++i){
//			if(i==v)continue;
//			dis[u][i]=max(dis[u][i],tmp+1);
//		}
//	}
//	return mx;
//}
//void solve(int u){
//	for(int it=head[u];it;it=e[it].nxt){
//		int v=e[it].v;
//		if(v==fa[u])continue;
//		solve(u);
//		for(int i=min(k,siz[v]);i>=0;--i){
//			for(int j=k;j>=0;--j){
//				dp[u][j][0]=min(dp[u][j][0],max(dis[u][v],dp[u][i][0]));
//			}
//		}
//	}
//}
bool vis[N];
int ans;
int d[N],tmp[N];
int f[N];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void solve(int u,int cnt){
	if(n-u+1+cnt<k)return;
	if(cnt>k)return;
	if(u>n){
		for(int i=1;i<=n;++i)d[i]=INF,f[i]=i;
		for(int i=1;i<=n;++i){
			if(!vis[i])continue;
			for(int it=head[i];it;it=e[it].nxt){
				f[find(e[it].v)]=find(i);
			}
//			cout<<i<<" ";
			for(int j=1;j<=n;++j){
				d[j]=min(d[j],dis[i][j]);
			}
		}
//		cout<<endl;
//		for(int i=1;i<=n;++i){
//			cout<<f[i]<<" ";
//		}
//		cout<<endl;
		int ccc=0;
		for(int i=1;i<=n;++i){
			if(!vis[i])continue;
			if(f[i]==i)ccc++;
		}
		if(ccc>2)return;
		int mx=0;
		for(int i=1;i<=n;++i)mx=max(mx,d[i]);
//		cout<<mx<<endl<<endl;
//		if(mx==1){
//			cout<<"!!!!!!!!!!!!!!"<<endl;
//		}
		ans=min(ans,mx);
		return;
	}
	solve(u+1,cnt);
	vis[u]=1;
	solve(u+1,cnt+1);
	vis[u]=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		clean();
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			add(u,v);
			vis[i]=0;
			d[i]=INF;
		}
		vis[n]=0;
		d[n]=INF;
		dfs1(1,0);
		dfs2(1,1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=dep[i]+dep[j]-2*dep[lca(i,j)];
//				cout<<"i:"<<i<<" j:"<<j<<" dis:"<<dis[i][j]<<'\n';
			}
		}
		ans=INF;
//		cout<<endl;
		solve(1,0);
//		get_dis(1);
		cout<<ans<<'\n';
//		solve(1);
	}
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
