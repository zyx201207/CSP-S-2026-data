#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define rep(i,s,t) for(int i=(s),lim=(t)+1;i!=lim;++i)
#define dep(i,s,t) for(int i=(s),lim=(t)-1;i!=lim;--i)
#define int long long
using namespace std;
bool _st;
time_t st;
constexpr int N=4e3+50,llinf=1e15;
template<typename T=int>T rd(){
	T x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())f=c==45?-1:f;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return  x*f; 
}
template<typename T>void print(T x){
	static long obuf[23],top0=0;
	if(x<0)putchar(45),x=-x;
	do obuf[top0++]=x%10,x/=10;while(x);
	while(top0)putchar(obuf[--top0]+48);
}
int sub,tt;
int f[N][N][3][2];
int n,k;
int fa[N];
vector<int>vec[N];
int low[N][2],to[N][2];
int dep[N];
void updlow(int u,int num,int v){
	if(low[u][0]<num)low[u][1]=low[u][0],low[u][0]=num,to[u][1]=to[u][0],to[u][0]=v;
	else low[u][1]=max(low[u][1],num);
}
void dfs1(int u){
	dep[u]=dep[fa[u]]+1,low[u][0]=low[u][1]=dep[u],to[u][0]=u;
	for(int v:vec[u]){
		if(v==fa[u])continue;
		dfs1(v);
		updlow(u,low[v][0],v);
		updlow(u,low[v][1],v);
	}
}
int g[N][3][2];
void dfs2(int u){
	f[u][0][0][0]=max(low[u][0]-dep[u],fa[u]!=0?
		to[fa[u]][0]==u?
			low[fa[u]][1]-dep[fa[u]]:low[fa[u]][0]-dep[fa[u]]:
			0);
	f[u][1][1][1]=low[u][0]-dep[u];
	for(int v:vec[u]){
		if(v==fa[u])continue;
		rep(j,1,k){
			rep(u,0,2){
				rep(v,0,1)g[j][u][v]=0;
			}
		}
		;
	}
}
void solve(){
	n=rd(),k=rd();
	rep(i,2,n){
		int u=rd(),v=rd();
		vec[u].emplace_back(v);
		vec[v].emplace_back(u);
	}
	rep(i,1,n){
		rep(j,1,k){
			rep(u,0,2){
				rep(v,0,1)f[i][j][u][v]=llinf;
			}
		}
	}
//	dfs1(1);
	if(k==1)print(n/2);
	else print((n-k-1)/3+1);
	puts("");
}
bool _ed;
signed main(){
	#ifndef NATSU
	file("hub");
	#endif
	#ifdef SAYHERE
	st=clock();
	#endif
	sub=rd(),tt=rd();
	while(tt--)solve();
	#ifdef SAYHERE
	cerr<<"\nTime:"<<clock()-st<<"ms";
	cerr<<"\nMemory:"<<(&_ed-&_st)/1048576.0<<"MB";
	#endif
	return 0;
}
