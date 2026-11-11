#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define ciallo continue
using namespace std;
inline int read(){
	char c=getchar();
	int res=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		res=res*10+c-48;
		c=getchar();
	}
	return res*f;
}
const int N=5e5+10,inf=5e14+10;
int c,n,m,d,q,s,t;
int w[N];
int k[N];
struct node{
	int destination;
	int cost;
};
vector<node> e[2*N];
int dis[2*N];
inline void dijkstra(){
	for(int i=1;i<=2*m;i++){
		dis[i]=inf;
	}
	queue<int> q;
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(node way:e[u]){
			if(dis[way.destination]>dis[u]+way.cost){
				dis[way.destination]=dis[u]+way.cost;
				q.push(way.destination);
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int idx=read();
			int ti=read();
			e[i+m].push_back({idx,ti});
			e[idx].push_back({i+m,ti});
		}
	}
	while(q--){
		s=read();
		t=read();
		dijkstra();
		cout<<w[s]+w[t]+dis[t]<<"\n";
	}
	return 0;
}
