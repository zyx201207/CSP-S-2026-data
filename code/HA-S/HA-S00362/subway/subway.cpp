#include<bits/stdc++.h>
#define N 505
#define M 500005
#define int long long
#define db double
#define ul unsigned long long
#define fo(i,l,r) for(int i=(l);i<=(r);i++)
#define rf(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
int T,n,m,k,a[M],q,op,x,y,z,ans,lst;
int e[N][N];
const int inf=1e18;
struct node{int i,v;};
vector<node>b[M];
void ckmax(int &x,int y){if(y>x)x=y;}
void ckmin(int &x,int y){if(y<x)x=y;}
int read(){
	int sum=0;bool f=0;char c=getchar();
	for(;c<48||c>57;c=getchar())if(c==45)f=1;
	for(;c>=48&&c<=57;c=getchar())sum=sum*10+(c&15);
	return f?-sum:sum; 
}
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	read();n=read();m=read();read();q=read();
	fo(i,1,m)a[i]=read();
	fo(i,1,n){
		k=read();
		while(k--){
			x=read();y=read();
			b[x].push_back({i,y});
		}
	}
	fo(i,1,n)fo(j,1,n)e[i][j]=inf;
	fo(i,1,n)e[i][i]=0;
	fo(i,1,m)
		for(auto j:b[i])
			for(auto k:b[i])
				ckmin(e[j.i][k.i],j.v+k.v);
	fo(k,1,n)
		fo(i,1,n)
			fo(j,1,n)
				ckmin(e[i][j],e[i][k]+e[k][j]);
	while(q--){
		x=read();y=read();
		ans=inf;
		for(auto j:b[x])
			for(auto k:b[y])
				ckmin(ans,j.v+k.v+e[j.i][k.i]);
		printf("%lld\n",ans+a[x]+a[y]);
	}
	return 0;
}
