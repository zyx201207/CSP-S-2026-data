#include <bits/stdc++.h>
using namespace std;
const int N=500005;
struct road{
	long long v,w;
};
vector <road> r[N];
priority_queue <pair<long long,long long>> xn;
long long f[N],w[N]
void dijstra(long long y){
	while (!xn.empty()){
		auto base=xn.top();
		long long u=base.second,cost=base.first;
		xn.pop();
		for (auto now:r[u]){
			if (f[now.v]>cost+now.w){
				f[now.v]=cost+now.w;
				xn.push({f[now.v],now.v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (long long i=1;i<=m;i++){
		cin >> w[i];
	}
	for (long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for (long long j=1;j<=k;j++){
			long long sn,tn;
			scanf("%lld%lld",&sn,&tn);
			r[sn].push_back({m+i,tn});
			r[m+i].push_back({sn,tn});
		}
	}
	for (long long i=1;i<=q;i++){
		for (long long j=1;j<=m+n;j++){
			f[j]=1e9;
		}
		long long x,y;
		scanf("%lld%lld",&x,&y);
		f[x]=0;
		xn.push({0,x});
		dijstra(y);
		printf("%lld\n",f[y]+w[x]+w[y]);
	}
	return 0;
}
