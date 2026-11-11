#include<bits/stdc++.h>
#define PLI pair<long long,int>
using namespace std;
const int N=5e5+505,M=2e7+10;
int c,n,m,d,q,k;long long dis[N],val[N],w[M];
int e[M],ne[M],h[N],idx;
bool vis[N];
struct query{
	int l,r,id;
	long long ans;
	bool operator<(const query&a)const{
		return l<a.l;
	}
}a[N];
inline bool cmp(query a,query b){
	return a.id<b.id;
}
inline long long read(){
	long long f=1,sum=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}
void print(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else print(x/10),putchar(x%10+'0');
}
inline void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
inline void dijkstra(int s){
	for(int i=1;i<=m+n;i++)vis[i]=0,dis[i]=0x3f3f3f3f3f3f3f3f;
	dis[s]=0;
	priority_queue<PLI,vector<PLI>,greater<PLI>> pq;
	pq.push({0,s});
	while(!pq.empty()){
		auto now=pq.top();
		pq.pop();
		int u=now.second;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];~i;i=ne[i]){
			int v=e[i];
			if(dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				pq.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)val[i]=read();
	memset(h,-1,sizeof h);
	for(int i=m+1;i<=m+n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			add(a,i,t),add(i,a,t);
		}
	}
	for(int i=1;i<=q;i++){
		a[i].l=read(),a[i].r=read(),a[i].id=i;
		if(a[i].l>a[i].r)swap(a[i].l,a[i].r);
	}
	sort(a+1,a+q+1);
	for(int i=1;i<=q;i++){
		if(a[i].l!=a[i-1].l)dijkstra(a[i].l);
		a[i].ans=dis[a[i].r]+val[a[i].l]+val[a[i].r];
	}
	sort(a+1,a+q+1,cmp);
	for(int i=1;i<=q;i++)print(a[i].ans),printf("\n");
	return 0;
}