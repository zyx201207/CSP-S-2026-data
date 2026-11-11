#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N=3010;
ll read() {
	ll x;scanf("%lld",&x);return x;
}
struct {
	int y,nxt;
}e[N*2];
int Link[N],len;
void add(int x,int y) {
	e[++len]={y,Link[x]};
	Link[x]=len;
}
int d[N],vis[N],cnt[N];
void dij(int s) {
	priority_queue<pair<ll,ll> >q;
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	d[s]=0;
	q.push({0,s});
	while(!q.empty()) {
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=Link[x];i;i=e[i].nxt) {
			int y=e[i].y;
			if(d[y]>d[x]+1) {
				d[y]=d[x]+1;
				cnt[y]=1;
				q.push({-d[y],y});
			}
			else if(d[y]==d[x]+1) cnt[y]++;
		}
	}
}
ll x[N];
void work() {
	ll n=read(),d=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(i==j) continue ;
			if(abs(x[i]-x[j])<=d) add(i,j);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) {
		dij(i);
		for(int j=i+1;j<=n;j++) {
			if(cnt[j]==2) ans++;
		}
	}
	printf("%d\n",ans);
	len=0;
	memset(Link,0,sizeof(Link));
	memset(e,0,sizeof(e));
}
main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int c=read(),t=read();t;t--) work();
	return 0;
}
