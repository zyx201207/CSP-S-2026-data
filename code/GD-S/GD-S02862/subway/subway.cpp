#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fir first
#define sec second
using namespace std;
const int N=1e6+1010;
int c,n,m,D,Q,res;
int kt[N],sz[N];//口到厅，经过的站点，厅到台,经过数量 
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
inline void add(int a,int b,int c){
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
	return ;
}
inline void dij(int st,int ed){
	memset(dist,0x3f,sizeof dist);
	queue<int> q;
	dist[st]=0;
	q.push(st);
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		if(u==ed){
			continue;
		}
		for(int i=h[u];~i;i=ne[i]){
			int j=e[i];
			if(dist[j]>dist[u]+w[i]){
				dist[j]=dist[u]+w[i];
				q.push(j);
			}
		}
	}
	res+=dist[ed];
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&kt[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&sz[i]);
		for(int j=1;j<=sz[i];j++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			add(i+1000000,x,y);
			add(x,i+1000000,y);
		}
	}
	while(Q--){
		int x,y;
		scanf("%lld%lld",&x,&y);//x->y;
		res=kt[x]+kt[y];
		dij(x,y);
		printf("%lld\n",res);
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

32
17
*/
