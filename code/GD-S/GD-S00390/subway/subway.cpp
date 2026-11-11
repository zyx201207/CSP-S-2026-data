#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+10;
void read(int &x){
	x=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c)) f=(c=='-'?-1:1),c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=x*f;
}
int c,n,m,d,q;
long long w[M];
int head[M*2],cnt=-1;
struct wbx{int to,nxt,w;};
vector<wbx>e;
void add(int x,int y,int w){cnt++,e.push_back({y,head[x],w}),head[x]=cnt;}
struct node{
	long long id,dis;
	bool operator <(const node x)const{
		return x.dis<dis;
	}
};
long long vis[M*2],dis[M*2],bj[M*2];
long long dijstra(int s,int t,int &id){
	priority_queue<node>q;
	q.push({s,0}),dis[s]=0,bj[s]=id;
	while(!q.empty()){
		int u=q.top().id;
		long long len=q.top().dis;
		q.pop();
		if(u==t) return len;
		if(vis[u]==id) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(bj[v]!=id) bj[v]=id,dis[v]=len+e[i].w,q.push({v,dis[v]});
			if(dis[v]>len+e[i].w) dis[v]=len+e[i].w,q.push({v,dis[v]});
 		}
	}
	id++;
	swap(s,t);
	q.push({s,0}),dis[s]=0,bj[s]=id;
	while(!q.empty()){
		int u=q.top().id;
		long long len=q.top().dis;
		q.pop();
		if(u==t) return len;
		if(vis[u]==id) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(bj[v]!=id) bj[v]=id,dis[v]=len+e[i].w,q.push({v,dis[v]});
			if(dis[v]>len+e[i].w) dis[v]=len+e[i].w,q.push({v,dis[v]});
 		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1,k;i<=n;i++){
		read(k);
		for(int j=1,a,t;j<=k;j++)
			read(a),read(t),add(i+m,a,t),add(a,i+m,t);
	}
	int id=1;
	while(q--){
		int x,y;
		read(x),read(y);
//		dijstra(x,y,++id);
		cout<<dijstra(x,y,++id)+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
