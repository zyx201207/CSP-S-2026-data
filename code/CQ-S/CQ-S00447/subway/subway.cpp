#include<bits/stdc++.h>
using namespace std;
struct app{long long jhx,lc;};
vector<app>dtz[500005];
long long n,m,q,zt[500005],lx[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>q>>q;
	for(long long i=1;i<=m;i++)scanf("%lld",&zt[i]);
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++){
			if(i==j)continue;
			lx[i][j]=1e18;
		}
	for(long long i=1;i<=n;i++){
		long long k;scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			long long x,y;scanf("%lld %lld",&x,&y),dtz[x].push_back({i,y});
		} 
	}
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<dtz[i].size();j++){
			for(long long k=j+1;k<dtz[i].size();k++){
				lx[dtz[i][j].jhx][dtz[i][k].jhx]=min(lx[dtz[i][j].jhx][dtz[i][k].jhx],dtz[i][k].lc+dtz[i][j].lc);
				lx[dtz[i][k].jhx][dtz[i][j].jhx]=lx[dtz[i][j].jhx][dtz[i][k].jhx];
			}
		}
	}
	for(long long k=1;k<=n;k++)
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)
				if(lx[k][i]+lx[k][j]<lx[i][j])
					lx[i][j]=lx[k][i]+lx[k][j],lx[j][i]=lx[k][i]+lx[k][j];
	while(q--){
		long long x,y;
		cin>>x>>y;
		long long sum=1e18;
		for(long long j=0;j<dtz[x].size();j++)
			for(long long k=0;k<dtz[y].size();k++)
				sum=min(sum,lx[dtz[x][j].jhx][dtz[y][k].jhx]+dtz[y][k].lc+dtz[x][j].lc);
		printf("%lld\n",sum+zt[x]+zt[y]);
//		cout<<sum+zt[x]+zt[y]<<endl;
	}
	return 0;
}

