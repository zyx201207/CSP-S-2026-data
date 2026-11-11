#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
inline int read(){
	int f=1,g=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		g=(g<<3)+(g<<1)+(c-'0');
		c=getchar();
	}
	return f*g;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar((x%10)+'0');
	return ;
}
const int M1=1e3+10,N=5e2+10,M=5e5+10;
int c,n,m,d,q,w[M],k[N];
vector<int>a[N],t[N];
vector<pii>g[M+N+20];
int dist[M1+20][M1+N+20];
bool f[M1+N+20];
priority_queue<pii,vector<pii>,greater<pii> >pq;
void dij(int fst){
	while(!pq.empty())pq.pop();
	pq.push({0,fst});
	for(int i=1;i<=m+n+10;i++)dist[fst][i]=LLONG_MAX/2,f[i]=0;
	dist[fst][fst]=0;
	while(!pq.empty()){
		pii ft=pq.top();
		pq.pop();
		int x=ft.second;
		if(f[x])continue;
		f[x]=1;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i].first,w=g[x][i].second;
			if(dist[fst][y]>dist[fst][x]+w){
				dist[fst][y]=dist[fst][x]+w;
				pq.push({dist[fst][y],y});
			}
		}
	}
	return ;
}
void solve1(){
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		a[i].assign(k[i]+1,0);
		t[i].assign(k[i]+1,0);
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();
			t[i][j]=read();
			g[a[i][j]].push_back({m+i,t[i][j]});
			g[m+i].push_back({a[i][j],t[i][j]});
		}
	}
	for(int i=1;i<=m;i++){
		dij(i);
	}
	while(q--){
		int l,r;
		l=read(),r=read();
		write(dist[l][r]+w[l]+w[r]);
		putchar('\n');
	}
	return ;
}
vector<int>h[M+N+20];
void solve2(){
	int T=0;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		a[i].assign(k[i]+1,0);
		t[i].assign(k[i]+1,0);
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();
			t[i][j]=read();
			T=t[i][j];
			h[a[i][j]].push_back(m+i);
			h[m+i].push_back(a[i][j]);
		}
	}
	queue<pii>pq;
	while(q--){
		int l,r,ans=0;
		bool ff=1;
		cin>>l>>r;
		while(!pq.empty())pq.pop();
		pq.push({l,0});
		vector<int>isf;
		isf.resize(n+m+10);
		while(!pq.empty()){
			int x=pq.front().first;
			int nw=pq.front().second;
			pq.pop();
			if(isf[x])continue;
			isf[x]=1;
			if(x==r){
				write(T*nw+w[l]+w[r]);
				putchar('\n');
				ff=0;
				break;
			}
			for(int i=0;i<h[x].size();i++){
				int y=h[x][i];
				pq.push({y,nw+1});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	if(c<=11){
		solve1();
		return 0;
	}
	else if(c<=19){
		solve2();
		return 0;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

