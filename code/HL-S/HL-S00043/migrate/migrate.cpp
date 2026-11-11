#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+10,M=5010;
const LL INF=0x7f7f7f7f7f7f7f7f;
int res[M][M],g[N],C,T,n;
bool st[N];
map<LL,int> cnt;
LL f[N],a[N],c[N],d;
priority_queue<LL,vector<LL>,greater<LL> > q;
void calc(int u){
	cnt.clear();
	while(q.size()) q.pop();
	int p=u;
	LL sum=0;
	for(int i=1;i<=n;i++){
		g[i]=0;
		f[i]=INF;
	}
	f[u]=0,g[u]=1;
	for(int i=u+1;i<=n;i++){
		sum+=c[i-1];
		q.push(f[i-1]);
		cnt[f[i-1]]+=g[i-1];
		while(sum>d){
			cnt[f[p]]-=g[p];
			sum-=c[p];
			p++;
		}
		while(q.size()&&cnt[q.top()]<1){
			q.pop();
		}
		f[i]=q.top()+1;
		if(cnt[q.top()]<=2) g[i]=cnt[q.top()];
		else g[i]=3;
		if(g[i]==2) res[u][i]=1;
		else res[u][i]=0;
	}
//	for(int i=1;i<=n;i++){
//		printf("f[%d] = %lld\n",i,f[i]);
//	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			c[i]=a[i+1]-a[i];
//			printf("c[%d] = %lld\n",i,c[i]);
		}
//		printf("tfeng %lld\n",c[4]*2);
//		calc(4);
		for(int i=1;i<n;i++) calc(i);
		LL ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=res[i][j];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}