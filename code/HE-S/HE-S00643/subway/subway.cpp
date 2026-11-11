#include <bits/stdc++.h>
using namespace std;

#define int long long
#define il inline
#define N 3300
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FR(a,b) for(auto (a):(b))
#define eb emplace_back

const int inf=1e18;

il int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';c=getchar();
	}
	return x*f;
} 

int c,m;
int n,d,q;
int dis[N],vis[N],w[N];



struct jie{
	int id,val;
};

vector<jie> tu[N*N];

il bool operator<(const jie &x,const jie &y){
	return x.val>y.val;
}

il void dijstra(int s){
	priority_queue<jie> q;
	FOR(i,0,(n+3)*m+3) vis[i]=0,dis[i]=inf;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		auto node=q.top();q.pop();
		if(vis[node.id]) continue;
		vis[node.id]=1;
		FR(v,tu[node.id]){
			if(dis[v.id]>dis[node.id]+v.val){
				dis[v.id]=dis[node.id]+v.val;
				q.push({v.id,dis[v.id]});
			}
		} 
	}
} 


signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	FOR(i,1,m){
		w[i]=read();
		tu[i].eb(jie{i+(n+1)*m,w[i]});
		tu[i+(n+1)*m].eb(jie{i,w[i]});
	}
	FOR(i,1,n){
		int k=read();
		int lst=0;
		FOR(j,1,k){
			int s1=read(),t1=read();
			if(!lst) lst=s1;
			else{
				tu[lst+m*i].eb(jie{s1+m*i,0});
				tu[s1+m*i].eb(jie{lst+m*i,0});
				lst=s1;
			}
			tu[s1+m*i].eb(jie{s1+m*(n+1),t1});
			tu[s1+m*(n+1)].eb(jie{s1+m*i,t1});
		}
	}
	
	FOR(i,1,q){
		int s=read(),t=read();
		dijstra(s);
		printf("%lld\n",dis[t]);
	}
	
	return 0;
} 
