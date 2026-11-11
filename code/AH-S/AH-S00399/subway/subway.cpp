#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[500005],vis[1000005],f[1000005],sum;
struct node{
	long long next,w;
};
vector<node>g[500005];
void di(long long st){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
	q.push({0ll,st});
	f[st]=0;
	while(!q.empty()){
		pair<long long,long long>h=q.top();q.pop();
		if(vis[h.second])continue;
		vis[h.second]=1;
		int u=h.second;
		for(auto x:g[u]){
			long long v=x.next;
			if(vis[v])continue;
			q.push({f[u]+x.w,v});
			f[v]=min(f[v],f[u]+x.w);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(long long j=1,v,w;j<=k;j++){
			scanf("%lld%lld",&v,&w);
			g[v].push_back({m+i,w});
			g[m+i].push_back({v,w});
		}
	}
	for(int i=1;i<=n+m;i++){
		f[i]=0x3f3f3f3f3f3f3f3f;
	}
	for(int i=1,st,ed;i<=q;i++){
		scanf("%d%d",&st,&ed);
		di(st);
		printf("%lld\n",f[ed]+a[st]+a[ed]);
		for(int j=1;j<=n+m;j++){
			f[j]=0x3f3f3f3f3f3f3f3f;
			vis[j]=0;
		}
	}
	return 0;
}
