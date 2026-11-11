#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0; char ch; bool f=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') f=1;
	else x=(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x; 
}
bool st1;
const int N=1e6+55;
int n,k;
int head[N],tot;
struct edge{
	int nex,y;
}e[N<<1];
void add(int x,int y){
	e[++tot]={head[x],y}; head[x]=tot;
}
int f[N],FA[N],g[N];
int fa[N],d[N];
int bz[N];
void dfs(int x,int f){
	d[x]=d[f]+1; fa[x]=f;
	bz[x]=1;
	for(int i=head[x];i;i=e[i].nex){
		int y=e[i].y;
		if(y==f) continue;
		dfs(y,x);
	}
}
void dfs2(int x,int f){
	d[x]=d[f]+1; fa[x]=f;
	for(int i=head[x];i;i=e[i].nex){
		int y=e[i].y;
		if(!bz[y]) continue;
		if(y==f) continue;
		dfs2(y,x);
	}
}
int mx[N];
void dfs3(int x,int fa){
	mx[x]=0;
	for(int i=head[x];i;i=e[i].nex){
		int y=e[i].y;
		if(!bz[y]||y==fa) continue;
		dfs3(y,x);
		mx[x]=max(mx[x],mx[y]+1);
	}
	f[mx[x]]++;
}
int R1,R2,S1,T1;
void calc(int x,int F){
	d[F]=0;
	for(int i=1;i<=n;i++) bz[i]=0;
	dfs(x,F);
	int S=0;
	for(int i=1;i<=n;i++){
		if(bz[i]&&d[i]>d[S]) S=i;
	}
	int T=0;
	dfs2(S,0);
	for(int i=1;i<=n;i++){
		if(bz[i]&&d[i]>d[T]) T=i;
	}
	int r1=-1,r2=-1;
	if(d[T]%2==1){
		r1=T;
		for(int i=1;i<=(d[T]-1)/2;i++) r1=fa[r1];
	}
	else{
		r1=T;
		for(int i=1;i<=(d[T]-1)/2;i++) r1=fa[r1];
		r2=fa[r1];
	}
	for(int i=0;i<=n+1;i++) f[i]=0;
	R1=r1,R2=r2; S1=S,T1=T;
//	cout<<"calc: "<<r1<<","<<r2<<"--------------\n";
	dfs3(r1,r2);
	if(r2!=-1) dfs3(r2,r1);
//	for(int i=0;i<=n;i++) cout<<f[i]<<" "; puts("");
	for(int i=n;i>=0;i--) f[i]+=f[i+1];
	for(int i=0;i<=n;i++) f[i]=max(f[i],1);
}
void solve(){
	n=read(),k=read();
	tot=0;
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) FA[i]=fa[i];
	int ans=n;
	calc(1,0);
	for(int i=0;i<=n;i++){
		if(f[i]<=k) ans=min(ans,i);
	}
//	if(k==2) ;
//	else{
		for(int x=2;x<=n;x++){
			calc(x,FA[x]);
			for(int i=0;i<=n;i++) g[i]=f[i];
			calc(FA[x],x);
	//		cout<<x<<" <-> "<<FA[x]<<"\n";
	//		for(int i=0;i<=n;i++) cout<<g[i]<<" "; puts("");
	//		for(int i=0;i<=n;i++) cout<<f[i]<<" "; puts("");
			for(int i=0;i<=n;i++){
				if(f[i]+g[i]<=k){
	//				if(i==1){
	//					
	//				cout<<x<<","<<FA[x]<<"!!\n";
	//		for(int i=0;i<=n;i++) cout<<g[i]<<" "; puts("");
	//		for(int i=0;i<=n;i++) cout<<f[i]<<" "; puts("");
	//				}
					ans=min(ans,i);
				}
			}
		}
//	}
	printf("%d\n",ans);
}
bool st2;
int main(){
//	cout<<(&st1-&st2)/1024/1024; return 0;
//	system("fc hub1.ans hub.out"); return 0;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read();
	int T=read();
	while(T--) solve();
	return 0;
}
/*
把直径中点当作根
二分答案
先贪心，选尽量少的点
f[x]表示x子树内，最远的还没解决的点
g[x]表示x子树内，最近的点的距离
如果此时达到了mid,那么先放
最后：
找到这些点形成的连通块，枚举断边 
-------------------------------------------
选一些点，顶多形成两个连通块，使得没被选的到最近被选的距离 max 尽量小
 枚举断边，然后两部分独立 
*/
