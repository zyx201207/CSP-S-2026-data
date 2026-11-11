#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> PII;
long long c,n,m,d,q;
long long ww[500010],res;
long long dist[1000010];
bool vis[1000010];
long long h[1000010],ne[1000010],e[1000010],w[1000010],idx;
priority_queue<PII,vector<PII>,greater<PII>> qq;
inline void add(int a,int b,int v){
	e[idx]=b,w[idx]=v,ne[idx]=h[a],h[a]=idx++;
}
void dij(int s){
	for(int i=1;i<=res;i++){
		dist[i]=1e15;
		vis[i]=0;
	}
	dist[s]=0;
	qq.push({0,s});
	while(!qq.empty()){
		int t=qq.top().second;
		qq.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=h[t];~i;i=ne[i]){
			int j=e[i];
			if(dist[j]>dist[t]+w[i]){
				dist[j]=dist[t]+w[i];
				qq.push({dist[j],j});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(h,-1,sizeof h);
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	res=m;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		int lst=0;
		for(int j=1;j<=x;j++){
			long long u,t;
			cin>>u>>t;
			res++;
			add(res,u,t);
			add(u,res,t);
			if(j!=1){
				add(lst,res,0);
				add(res,lst,0);
			}
			lst=res;
		}
	}
	while(q--){
		long long l,r;
		cin>>l>>r;
		dij(l);
		cout<<ww[l]+ww[r]+dist[r]<<"\n";
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
