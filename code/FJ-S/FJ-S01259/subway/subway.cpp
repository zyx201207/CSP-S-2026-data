#include<bits/stdc++.h>
#define int long long
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3f
#else 
#define inf 0x3f3f3f3f
#endif
#define ulp(i,a,b) for(int i=a;i<=b;++i)
#define dlp(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
inline int read(){
	char c=getchar();
	bool f=false;
	int num=0;
	while(!isdigit(c)){
		if(c=='-')f=true;
		c=getchar();
	}
	while(isdigit(c)){
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar(); 
	}
	return f?-num:num;
}
void write(int x,char ed=' '){
	if(x<0)putchar('-'),x=-x;
	int stk[65],top=0;
	do{
		stk[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar(stk[top--]+'0');
	putchar(ed);
}
#define N 505
#define M 500005
#define Q 100005
//每个地铁站至多20线路
int c,n,m,d,q;
int w[M];
int dis[N][N];
int ww[N][N];
bool vis[N];
vector<pii> G[M];
vector<pii> ZT[N];
//站厅 1~m
//站台 m+1~m+n 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	ulp(i,1,m)w[i]=read();
	ulp(i,1,n){
		int k=read();
		ulp(j,1,k){
			int x=read(),tt=read();
			G[x].pb({i,tt});
		}
	} 
	memset(ww,0x3f,sizeof ww);
	ulp(u,1,m){
		ulp(j,0,(int)G[u].size()-1){
			ulp(k,j+1,(int)G[u].size()-1){
				ww[G[u][j].fir][G[u][k].fir]=min(ww[G[u][j].fir][G[u][k].fir],G[u][j].sec+G[u][k].sec);
				ww[G[u][k].fir][G[u][j].fir]=min(ww[G[u][k].fir][G[u][j].fir],G[u][j].sec+G[u][k].sec);
			}
		}
	}
	ulp(i,1,n){
		ulp(j,1,n){
			if(ww[i][j]!=inf)ZT[i].pb({j,ww[i][j]});
		}
	}
	memset(dis,0x3f,sizeof dis);
	ulp(i,1,n){
		dis[i][i]=0;
		ulp(j,1,n)vis[j]=false;
		priority_queue<pii,vector<pii>,greater<pii>> pq;
		pq.push({0,i});
		while(!pq.empty()){
			int u=pq.top().sec;
			pq.pop();
			if(vis[u])continue;
			vis[u]=true;
			for(pii t : ZT[u]){
				int v=t.fir,w=t.sec;
				if(!vis[v]&&dis[i][v]>dis[i][u]+w){
					dis[i][v]=dis[i][u]+w;
					pq.push({dis[i][v],v});
				} 
			}
		}
	}
//	ulp(i,1,n)ulp(j,1,n){
//		write(dis[i][j],j==n?'\n':' ');
//	}
	while(q--){
		int x=read(),y=read();
		int ans=inf;
		for(pii t1 : G[x]){
			for(pii t2 : G[y]){
				 ans=min(ans,dis[t1.fir][t2.fir]+t1.sec+t2.sec);
			}
		}
		write(ans+w[x]+w[y],'\n');
	}
	return 0;
}
//我们考虑最朴素的想法
//就是对于每一次的询问都跑一遍最短路
//大概是 m/m量级的即需要 O(mlogm) 的复杂度
//大概 O(qmlogm) 这肯定不能接受
//我们想一下有没有什么简单的办法
//现在想了一个O(d^2m+qn^2)的做法 
//期望:1 2 3 4 5 6 7 8
//12 13 14 15 20 21
//14*4=56  
//过样例跑路 16:31 
//复杂度 dij部分 n^nlogn+d^2q+d^2m 
 
