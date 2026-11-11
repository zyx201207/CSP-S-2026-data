#include<stdio.h>
#include<vector>
typedef long long ll;
const int N=2e6+5;
std::vector<int> v;
int C,t,n,p[N],vis[N],dp[N],g[N],h[N];
ll d,x[N];
std::vector<int> to[N];
int dis[N],count[N],q[N],hh,tt;
ll solve(int s){
	v.clear();
	int now=s;
	while(1){
		vis[now]=1,v.emplace_back(now);
		if(p[now]!=now) now=p[now];
		else break;
	}
	for(int i=0;i<v.size()+2;i++) dp[i]=0,g[i]=0,h[i]=0;
	for(int i=(int)v.size()-2;i>=1;i--){
		dp[i]=(p[v[i]-1]==v[i+1]? (p[v[i]-2]==v[i+1]? 0:h[i+1]):(p[v[i]-1]==v[i+1]-1&&v[i-1]!=v[i]-1? g[i+1]:dp[i+1]));
		if(v[i]-v[i-1]>=2) dp[i]+=p[v[i]-1]-p[v[i]-2];
		if(v[i]-v[i-1]>=2) g[i]=(p[v[i]-1]==v[i+1]? 0:(p[v[i]-1]==v[i+1]-1? g[i+1]:dp[i+1]));
		h[i]=1+v[i+1]-p[v[i]-1]+(p[v[i]-1]==v[i+1]? 0:h[i+1]);
//		if(s==1) printf("sdf:%d %d %d %d\n",v[i],dp[i],g[i],h[i]);
	}
	ll sum=0;
	for(int i=0;i<(int)v.size()-1;i++) sum+=dp[i+1];
	return sum;
}
void bfs(int s){
	for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f,count[i]=0;
	dis[s]=0,count[s]=1;
	hh=1,tt=0;
	q[++tt]=s;
	while(hh<=tt){
		int u=q[hh++];
		for(auto i:to[u]){
			if(dis[u]+1<dis[i]) dis[i]=dis[u]+1,count[i]=count[u],q[++tt]=i;
			else if(dis[u]+1==dis[i]) count[i]=std::min(10,count[i]+count[u]);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	scanf("%d%d",&C,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		if(n<=300){
			for(int i=1;i<=n;i++) scanf("%lld",&x[i]),to[i].clear();
			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(x[j]-x[i]<=d) to[i].emplace_back(j);
			int ans=0;
			for(int i=1;i<=n;i++){
				bfs(i);
				for(int j=i;j<=n;j++) ans+=count[j]==2;
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]),vis[i]=0;
		for(int i=n,j=n;i>=1;i--){
			while(j>i&&x[j]-x[i]>d) j--;
			p[i]=j;
		}
		ll ans=0;
		for(int i=1;i<=n;i++) if(vis[i]==0) ans+=solve(i);
		printf("%lld\n",ans);
	}
	return 0;
}
