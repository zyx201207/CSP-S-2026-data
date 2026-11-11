#include<bits/stdc++.h>
using namespace std;
vector<long long> t[501],T[500001];
long long dis[501][501];
long long M=1e18;
vector<int> a[501],l[500001];
long long w[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int K;
		scanf("%d",&K);
		for(int j=1;j<=K;j++){
			int na;
			long long nw;
			scanf("%d%lld",&na,&nw);
			a[i].push_back(na);
			t[i].push_back(nw);
			l[na].push_back(i);
			T[na].push_back(nw);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=M;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int u=l[i].size();
		for(int fr=0;fr<u;fr++){
			for(int to=0;to<u;to++){
				int afr=l[i][fr],ato=l[i][to];
				dis[afr][ato]=min(dis[afr][ato],T[i][fr]+T[i][to]);
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)if(dis[i][j]>dis[i][k]+dis[k][j])dis[i][j]=dis[i][k]+dis[k][j];
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long nmin=M;
		int ux=l[x].size(),uy=l[y].size();
		for(int fr=0;fr<ux;fr++){
			for(int to=0;to<uy;to++){
				nmin=min(nmin,dis[l[x][fr]][l[y][to]]+T[x][fr]+T[y][to]);
			}
		}
		printf("%lld\n",nmin+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
