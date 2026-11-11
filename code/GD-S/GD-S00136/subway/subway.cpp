#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long dist,to,pre;
}d;
inline long long read(){
	long long p=1,num=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')p=-p;
		c=getchar();
	}
	while(isdigit(c)){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*p;
}
long long c,n,m,dd,q,w[500010],k[510],fa[500010],dist[500010];
bool vis[500010];
vector<long long>e[500010],luxian[500010],xianlu[500010];
int t[510][500010];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();dd=read();q=read();
	for(long long i=1;i<=m;i++){
		w[i]=read();
	}
	for(long long i=1;i<=n;i++){
		k[i]=read();
		for(long long j=1,a,b,pre=0;j<=k[i];j++){
			a=read();
			b=read();
			if(pre!=0){
				e[a].push_back(pre);
				e[pre].push_back(a);
			}pre=a;
			xianlu[a].push_back(i);
			luxian[i].push_back(a);
			t[i][a]=b;
		}
	}
	for(long long i=1;i<=m;i++){
		sort(xianlu[i].begin(),xianlu[i].end());
		sort(e[i].begin(),e[i].end());
	}
	for(long long i=1;i<=q;i++){
		sort(luxian[i].begin(),luxian[i].end());
	}
	while(q--){
		long long u,v;
		u=read();
		v=read();
		long long ans=w[u]+w[v];
		memset(vis,false,sizeof(vis));
		memset(fa,0,sizeof(fa));
		fill(dist+1,dist+m+1,LLONG_MAX);
		dist[u]=0;
		queue<edge>q;
		q.push({0,u,0});
		while(!q.empty()){
			d=q.front();q.pop();
			//cout<<d.to<<":\n";
			if(d.to==v){
				dist[d.to]+=t[d.pre][d.to];
				break;
			}
			if(vis[d.to])continue;
			vis[d.to]=true;
			for(long long to:e[d.to]){
				//cout<<to<<'\n';
				bool falg=false;
				long long len=0,add=d.pre;
				if(d.pre==0){
					falg=true;
					for(long long i:xianlu[to]){
						if(*lower_bound(xianlu[d.to].begin(),xianlu[d.to].end(),i)==i){
							add=i;
							len=t[i][d.to];
							//cout<<i<<'\n';
							break;
						}
					}
				}else{
					falg=(d.pre==*lower_bound(xianlu[to].begin(),xianlu[to].end(),d.pre));
				}
				if(!falg){
					for(long long i:xianlu[to]){
						if(*lower_bound(xianlu[d.to].begin(),xianlu[d.to].end(),i)==i){
							len=t[i][d.to]+t[d.pre][d.to];
							add=i;
							break;
						}
					}
				}
				if(dist[to]>dist[d.to]+len){
					dist[to]=dist[d.to]+len;
					long long pre=0;
					pre=add;
					//cout<<dist[to]<<' '<<dist[d.to]<<' '<<len<<' '<<pre<<" 1\n";
					q.push({dist[to],to,pre});
				}else{
					//cout<<dist[to]<<' '<<dist[d.to]<<' '<<len<<' '<<add<<'\n';
				}
			}
			//cout<<'\n';
		}
		cout/*<<"    "*/<<dist[v]+ans<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

