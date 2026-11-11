#include<bits/stdc++.h>
#define il inline
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define vpii vector<pii>
#define pb push_back
#define mst(a,x) memset(a,x,sizeof a)
using namespace std;
const int N=510,M=5e5+10,INF=0x3f3f3f3f;
int C,n,m,d,q,w[M];
ll f[N][N];
vpii vc[M];
void QwQ() {
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) {
		int k; scanf("%d",&k);
		for(int j=1;j<=k;j++) {
			int x,y; scanf("%d%d",&x,&y);
			vc[x].pb({i,y});
		}
	}
	mst(f,0x3f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) {
		for(auto p:vc[i]) for(auto q:vc[i])
			f[p.fir][q.fir]=min(f[p.fir][q.fir],(ll)p.sec+q.sec);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int s,t;q--;) {
		scanf("%d%d",&s,&t);
		ll as=1e18;
		for(auto p:vc[s]) for(auto q:vc[t])
			as=min(as,(ll)w[s]+w[t]+p.sec+q.sec+f[p.fir][q.fir]);
		printf("%lld\n",as);
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
	while(T--) QwQ();
}
/*
一开始以为算上坐地铁时间不会做qwq 
*/ 
