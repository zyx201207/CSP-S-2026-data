#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
long long c,n,m,d,q,w[521629],k,a,t,x,y,di[521629],f[521629],r,re[162999];
struct Q{long long x,y,d;}qu[162999];
bool cp(Q a,Q b){
	return a.x<b.x;
}
vector<pair<long long,long long> >g[521629];
long long BFS(long long u){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
	fill(f+1,f+n+m+1,0);	
	q.push(make_pair(0,u)),di[u]=0,f[u]=1;
	while(q.size()){
		long long dis=q.top().first,u=q.top().second;q.pop();
		for(long long i=0;i<g[u].size();++i){
			long long v=g[u][i].first,w=g[u][i].second;
			if(!f[v]){
				di[v]=dis+w;
				f[v]=1;
				q.push(make_pair(di[v],v));
			}
		}
	}
//	for(long long i=1;i<=m+n;++i){
//		printf("di[%lld]=%lld\n",i,di[i]);
//	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(long long i=1;i<=m;++i)w[i]=read();
	for(long long i=1;i<=n;++i){
		k=read();
		for(long long j=1;j<=k;++j){
			a=read(),t=read();
			g[a].push_back(make_pair(m+i,t));
			g[m+i].push_back(make_pair(a,t));
		}
	}for(long long i=1;i<=q;++i){
		x=read(),y=read();
		if(x>y)swap(x,y);
		qu[i].x=x,qu[i].y=y;
		qu[i].d=i;
	}
	sort(qu+1,qu+q+1,cp);
	for(long long i=1;i<=q;++i){
		if(qu[i].x!=qu[i-1].x)BFS(qu[i].x);
		re[qu[i].d]=di[qu[i].y]+w[qu[i].x]+w[qu[i].y];
	}for(long long i=1;i<=q;++i){
		printf("%lld\n",re[i]);
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


*/
