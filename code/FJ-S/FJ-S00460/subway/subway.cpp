#include<bits/stdc++.h>
using namespace std;
const long long N=510,M=10000+10;

long long cc,n,m,d,q;
long long w[M],a[N][M],t[N][M],k[N],x,y;
long long Map[M][M],cnt;
vector<long long>aa[M];

long long dis[M],c[M];
void dijkstra(long long u){
	memset(c,0,sizeof(c));
	memset(dis,0x3f,sizeof(dis));
	long long minx=LONG_LONG_MAX,idx,cnt2=0;
	for(long long i=1;i<=cnt;++i){
		dis[i]=Map[u][i];
	}
//		cout<<Map[2][3];
	while(cnt2<=cnt){
		c[u]=1;
		minx=LONG_LONG_MAX;
		for(long long i=1;i<=cnt;++i){
			if(!c[i]&&dis[i]<minx){
				minx=dis[i];
				idx=i;
			}
		}
//		cout<<u<<endl;
		u=idx;
//		for(long long i=1;i<=cnt;++i){
			for(long long j=0;j<aa[u].size();++j){
				long long k=aa[u][j];
				dis[k]=min(dis[k],dis[u]+Map[u][k]);
			}
//		}
		++cnt2;
	}
}

int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(Map,0x3f,sizeof(Map));
	scanf("%lld%lld%lld%lld%lld",&cc,&n,&m,&d,&q);
	cnt=2*m;
	for(long long i=1;i<=m;++i)scanf("%lld",&w[i]);
	for(long long i=1;i<=n;++i){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];++j){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			if(Map[a[i][j]][a[i][j]+m]!=Map[0][0]){
				++cnt;
				aa[cnt].push_back(a[i][j]+m);
				aa[a[i][j]+m].push_back(cnt);
				aa[cnt].push_back(a[i][j-1]);
				aa[a[i][j-1]].push_back(cnt);
				Map[cnt][a[i][j]+m]=t[i][j];
				Map[a[i][j]+m][cnt]=t[i][j];
				Map[cnt][a[i][j-1]]=0;
				Map[a[i][j-1]][cnt]=0;
				a[i][j]=cnt;
			}
			else{
				aa[a[i][j]].push_back(a[i][j]+m);
				aa[a[i][j]+m].push_back(a[i][j]);
				aa[a[i][j]].push_back(a[i][j-1]);
				aa[a[i][j-1]].push_back(a[i][j]);
				Map[a[i][j]][a[i][j]+m]=t[i][j];
				Map[a[i][j]+m][a[i][j]]=t[i][j];
				Map[a[i][j]][a[i][j-1]]=0;
				Map[a[i][j-1]][a[i][j]]=0;
			}
		}
	}
	for(long long i=1;i<=cnt;++i)Map[i][i]=0;
	for(long long i=1;i<=q;++i){
		scanf("%lld%lld",&x,&y);
		dijkstra(x+m);
		printf("%ld\n",dis[y+m]+w[x]+w[y]);
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
