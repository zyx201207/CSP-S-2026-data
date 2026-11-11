#include<bits/stdc++.h>
using namespace std;
#define int long long
//1-6以每个点为起点跑dijkstra
//11-12直接用公差算
//估分30分 
int c,t,n,d,dis[305],cnt[305],a[2000005];
vector<int> g[305];
bool flag[305];
struct node{
	int x,d;
};
bool operator<(const node &x,const node &y){
	return x.d>y.d;
}
priority_queue<node> q;
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(flag,0,sizeof(flag));
	dis[s]=0,cnt[s]=1;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().x;
		q.pop();
		if(flag[u])continue;
		flag[u]=true;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push({v,dis[v]});
			}else if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
		}
	}
}
void solve1(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		g[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++)
			if(cnt[j]==2)ans++;
	}
	printf("%lld\n",ans/2);
}
void solve2(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	int k=d/(a[2]-a[1]);
	if(k<=1)printf("0\n");
	else printf("%lld\n",max(0ll,n-(2*k-1)));
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		if(c<=6)solve1();
		else solve2();
	}
	return 0;
}
