#include<bits/stdc++.h>
using namespace std;
const long long N=505;
const int M=5*1e5+5;
const long long inf=1e16;//1e12
long long f[N][N],n,m,d,qq,tt,a[M];
vector<pair<long long,long long> > g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&tt,&n,&m,&d,&qq);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			f[i][j]=inf;
		}
		f[i][i]=0;
	}
	for(long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			for(auto z:g[x]){
				f[z.first][i]=min(f[z.first][i],z.second+y);
				f[i][z.first]=min(f[i][z.first],z.second+y);
			}
			g[x].push_back(make_pair(i,y));
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(qq--){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long ans=inf;
		for(auto p:g[x]){
			for(auto q:g[y]){
				ans=min(ans,p.second+q.second+f[p.first][q.first]);
			}
		}
		ans+=a[x];
		ans+=a[y];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 
