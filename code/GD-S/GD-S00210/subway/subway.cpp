#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int c,n,m,d,q,szs[505],szt[500005];
long long w[500005],t,dis[505][505];
bool tct[500005];
vector<pair<int,long long>>s[505],sta[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1,k,a;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d %lld",&a,&t);
			s[i].push_back(make_pair(a,t));
			szs[i]++;
			sta[a].push_back(make_pair(i,t));
			szt[a]++;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=1e18;
	for(int i=1;i<=n;i++)for(int j=0;j<szs[i];j++)
	    for(int k=0;k<szt[s[i][j].first];k++)
	        dis[i][sta[s[i][j].first][k].first]=min(dis[i][sta[s[i][j].first][k].first],s[i][j].second+sta[s[i][j].first][k].second);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	// for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d %d %lld\n",i,j,dis[i][j]);
	for(int i=1,x,y;i<=q;i++){
		scanf("%d %d",&x,&y);
		t=1e18;
		for(int j=0;j<szt[x];j++)for(int k=0;k<szt[y];k++){
			t=min(t,w[x]+w[y]+dis[sta[x][j].first][sta[y][k].first]+sta[x][j].second+sta[y][k].second);
			// printf("%d %d %lld\n",sta[x][j].second,sta[y][k].second,w[x]+w[y]+dis[sta[x][j].first][sta[y][k].first]+sta[x][j].second+sta[y][k].second);
		}
		printf("%lld\n",t);
	}
	return 0;
}
