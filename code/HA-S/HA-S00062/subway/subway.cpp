#include<iostream>
#include<ctime>
#include<vector>
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define rep(i,s,t) for(int i=(s),lim=(t)+1;i!=lim;++i)
#define dep(i,s,t) for(int i=(s),lim=(t)-1;i!=lim;--i)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define int long long
#define fi first
#define se second
using namespace std;
using pii=pair<int,int>;
bool _st;
time_t st;
constexpr int M=5e5+30,N=530,llinf=1e18;
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
int f[N][N];
int sub,n,m,d,q;
int b[M];
vector<pii>vec[M];
void input(){
	sub=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	rep(i,1,m)b[i]=rd();
	rep(i,1,n){
		int k=rd();
		rep(j,1,k){
			int v=rd(),w=rd();
			vec[v].emplace_back(i,w);
		}
		rep(j,1,n)f[i][j]=llinf;
		f[i][i]=0;
	}
}
void init(){
	rep(i,1,m){
		for(auto itu:vec[i]){
			int u=itu.first,wu=itu.second;
			for(auto itv:vec[i]){
				int v=itv.first,wv=itv.second;
				if(u==v)continue;
				f[u][v]=min(f[u][v],wu+wv);
			}
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
}
void output(){
	while(q--){
		int s=rd(),t=rd();
		int ans=llinf;
		for(auto its:vec[s]){
			for(auto itt:vec[t]){
				int cur=b[s]+b[t]+its.se+itt.se+f[its.fi][itt.fi];
				ans=min(cur,ans);
			}
		}
		print(ans),putchar(10);
	}
}
void solve(){
	input();
	init();
	output();
}
bool _ed;
signed main(){
	#ifndef NATSU
	file("subway");
	#endif
	#ifdef SAYHERE
	st=clock();
	#endif
	int tt=1;
	while(tt--)solve();
	#ifdef SAYHERE
	cerr<<"\nTime:"<<clock()-st<<"ms";
	cerr<<"\nMemory:"<<(&_ed-&_st)/1048576.0<<"MB";
	#endif
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
