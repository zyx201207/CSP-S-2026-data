#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long k=0,p=1,c=getchar();
	while(c!=EOF&&(c>'9'||c<'0')){
		if(c=='-')p*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*p;
}
void putt(long long x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)putt(x/10);
	putchar(x%10+'0');
}

const long long N=5e5+5;
struct edge{
	long long to,w;
};
vector<vector<edge> > adj;
long long dist[N];
void diji(){
	priority_queue<long long,
	vector<long long>,
	greater<long long > > pq;
}
long long c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(long long i=0;i<m;i++){
		dist[i]=read();
	}
	for(long long i=1;i<=n;i++){
		long long x=read();
		for(long long j=0;j<x;j++){
			long long v=read(),w=read();
			adj[i].push_back({v,w});
		}
	}
	for(long long i=0;i<q;i++){
		long long l=read(),r=read();
		solve(l,r);
	}
	return 0;
} 
