#include<bits/stdc++.h>
using namespace std;

#define N 501

long long min(long long x,long long y){
	return (x<y?x:y);
}
long long n,m,s,e,q,d,c,dis[N][N],w[500005],op,u,v,ans;
long long p=1;

struct pos{
	long long to,w;
};
vector<pos>g[500001];

void solve(){
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i!=j) dis[i][j]=p;
		}
	}
	for(long long x=1;x<=m;x++){
		for(long long i=0;i<(long long)g[x].size();i++){
			for(long long j=0;j<i;j++){
				if(g[x][i].to!=g[x][j].to){
					dis[g[x][i].to][g[x][j].to]=min(dis[g[x][i].to][g[x][j].to],g[x][i].w+g[x][j].w);
					dis[g[x][j].to][g[x][i].to]=min(dis[g[x][j].to][g[x][i].to],g[x][i].w+g[x][j].w);
				}
			}
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<i;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
				dis[j][i]=min(dis[i][k]+dis[k][j],dis[j][i]);
			}
		}
	}
	return;
}



int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    //for(int i=1;i<=45;i++) p*=2;
    p<<=45;
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++) cin>>w[i];
    for(long long i=1;i<=n;i++){
    	cin>>op;
    	for(long long j=1;j<=op;j++){
    		cin>>u>>v;
    		g[u].push_back({i,v});
		}
	}
	solve();
	while(q--){
		cin>>s>>e;
		ans=p;
		for(auto ks:g[s]){
			for(auto ky:g[e]){
				ans=min(ans,dis[ks.to][ky.to]+ks.w+ky.w);
			}
		}
		ans+=w[s]+w[e];
		cout<<ans<<'\n';
	}
	return 0;
}
