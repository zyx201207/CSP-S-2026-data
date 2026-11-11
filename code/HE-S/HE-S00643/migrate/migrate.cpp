#include <bits/stdc++.h>
using namespace std;

#define int long long
#define il inline
#define N 5200
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

int c,T;
int n,d;
int a[N],dis[N],vis[N],cnt[N];

vector<int> tu[N];

struct jie{
	int id,to;
};

il bool operator<(const jie &x,const jie &y){
	return x.to>y.to;
}

il void dijstra(int s){
	priority_queue<jie> q;
	FOR(i,0,n+1){
		dis[i]=inf,vis[i]=cnt[i]=0;
	}
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()){
		auto node=q.top();q.pop(); 
		if(vis[node.id]) continue;
		vis[node.id]=1;
		for(auto v:tu[node.id]){
			if(dis[v]==dis[node.id]+1){
				cnt[v]++;
			}
			if(dis[v]>dis[node.id]+1){
				dis[v]=dis[node.id]+1;
				cnt[v]=cnt[node.id];
				q.push({v,dis[v]});
			}
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		FOR(i,1,n) a[i]=read();
		
		FOR(i,1,n) tu[i].clear();
		
		FOR(i,1,n){
			FOR(j,1,n){
				if(i==j) continue;
				if(abs(a[j]-a[i])<=d) tu[i].eb(j);
			}
		}
		
		int ans=0;
		FOR(i,1,n){
			dijstra(i); 
			FOR(j,i+1,n){
				if(cnt[j]==1){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
