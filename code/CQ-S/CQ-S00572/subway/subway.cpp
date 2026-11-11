#include<bits/stdc++.h>
using namespace std;
namespace estidi{
	const int mn=503,mm=500003;
	const long long inf=21474836477777777;
	long long d[mn][mn];
	vector<pair<int,long long>>r[mm];
	int t[mm];
	int main(){
		int sc,n,m,md,q,cnt,st,x,y;
		long long w,ans;
		scanf("%d%d%d%d%d",&sc,&n,&m,&md,&q);
		for(int i=1;i<=m;i++)
			scanf("%d",&t[i]);
		for(int i=1;i<=n;i++){
			scanf("%d",&cnt);
			while(cnt--){
				scanf("%d%lld",&st,&w);
				r[st].push_back({i,w});
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					d[i][j]=inf;
		for(int i=1;i<=m;i++)
			for(int j=0;j<r[i].size();j++)
				for(int k=0;k<j;k++){
					d[r[i][j].first][r[i][k].first]=min(d[r[i][j].first][r[i][k].first],r[i][j].second+r[i][k].second);
					d[r[i][k].first][r[i][j].first]=min(d[r[i][k].first][r[i][j].first],r[i][j].second+r[i][k].second);
				}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		while(q--){
			scanf("%d%d",&x,&y);
			ans=21474836477777777;
			for(int i=0;i<r[x].size();i++)
				for(int j=0;j<r[y].size();j++)
					ans=min(ans,d[r[x][i].first][r[y][j].first]+r[x][i].second+r[y][j].second);
			printf("%lld\n",ans+t[x]+t[y]);
		}
		return 0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	estidi::main();
	return 0;
}
