#include<bits/stdc++.h>
using namespace std;
long long ans,c,t,n,D,x[2000010],h[2000010],num,dp[2000010],d[2000010],vis[2000010];
struct node {
	long long v,nex;
} e[2000010];
void add(long long u,long long v) {
	e[++num].v=v;
	e[num].nex=h[u];
	h[u]=num;
}
void dj(long long s) {
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
	q.push(make_pair(0,s));
	for (long long i=1; i<=n; i++)vis[i]=0;
	while(!q.empty()) {
		long long u=q.top().second,minn=q.top().first;
		q.pop();
		if (vis[u])continue;
		vis[u]=1;
		for(long long i=h[u]; i; i=e[i].nex) {
			long long v=e[i].v;
			if (d[v]>minn+1) {
				dp[v]=dp[u];
				d[v]=minn+1;
				q.push(make_pair(d[v],v));
			} else if (d[v]==minn+1) {
				dp[v]+=dp[u];
			}
		}
	}
	for (long long i=1; i<=n; i++) {
		if (i!=s&&dp[i]==2)ans++;
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		ans=0;
		num=0;
		scanf("%lld%lld",&n,&D);
		if (n<=5000*2) {
			for (long long i=1; i<=n; i++) {
				h[i]=0;
				scanf("%lld",&x[i]);
			}
			for (long long i=2; i<=n; i++) {
				for (long long j=i-1; j>=1; j--) {
					if (abs(x[i]-x[j])>D)break;
					add(j,i);
				}
			}
			for (long long i=1; i<=n; i++) {
				for (long long j=1; j<=n; j++) {
					dp[j]=0;
					d[j]=1e18;
				}
				dp[i]=1;
				d[i]=0;
				dj(i);
			}
			printf("%lld\n",ans);
		}else{
			for (long long i=1; i<=n; i++) {
				scanf("%lld",&x[i]);
			}
			long long numx=D/(x[2]-x[1]);
			long long tt=numx;
			for (long long i=1;i<=n;i++){
				if (n/numx!=1&&numx!=1)ans+=n/(numx+1);
				numx+=tt;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
