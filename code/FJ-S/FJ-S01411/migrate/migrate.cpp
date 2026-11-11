#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
long long c,t,n,d,x[5229],df[5229],di[5229][5229],ok[5229][5229],f[5229],l,r,re;
vector<long long>g[5229];
void BFS(long long no){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
	fill(f+1,f+n+1,0);	
	q.push(make_pair(0,no)),di[no][no]=0,f[no]=1;
	while(q.size()){
		long long dis=q.top().first,u=q.top().second;q.pop();
		for(long long i=0;i<g[u].size();++i){
			long long v=g[u][i];
			if(f[v]&&di[no][v]==dis+1){
				++ok[no][v];
			}
			if(!f[v]){
				++ok[no][v];
				di[no][v]=dis+1;
				f[v]=1;
				q.push(make_pair(di[no][v],v));
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read(),re=0;
		for(long long i=1;i<=n;++i){
			x[i]=read();g[i].clear();
		}
		for(long long i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				ok[i][j]=di[i][j]=0;
			}
			for(long long j=i;j<=n;++j){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}for(long long i=1;i<=n;++i){
			BFS(i);
		}
		for(long long l=1;l<=n-2;++l){
			for(long long r=l+2;r<=n;++r){
				if(ok[l][r]==2){	
					++re;
				}	
			}
		}printf("%lld\n",re);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
