#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10,M=510;
struct node{
	long long u,v;
};
long long c,n,m,d,q,tot,w[N],k[N],vis[N],dis[M][M];
vector<node>v[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for (long long i=1;i<=m;i++){
		cin >>w[i];
	}
	tot=m;
	for (long long i=1;i<=n;i++){
		++tot;
		cin >>k[i];
		for (long long j=1;j<=k[i];j++){
			long long a,b;
			cin >>a>>b;
			v[tot].push_back({a,b});
			v[a].push_back({tot,b});
		}
	}
	for (long long i=1;i<=n;i++){
		for (long long j=1;j<=n;j++){
			if (i!=j)dis[i][j]=1e18;
			else dis[i][j]=0;
		}
	}
	for (long long i=1;i<=m;i++){
		for (long long j=0;j<v[i].size();j++){
			for (long long k=0;k<v[i].size();k++){
				dis[v[i][j].u-m][v[i][k].u-m]=min(dis[v[i][j].u-m][v[i][k].u-m],v[i][j].v+v[i][k].v);
			}
		}
	}
	for (long long k=1;k<=n;k++){
		for (long long i=1;i<=n;i++){
			for (long long j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		long long s,t,ans=1e18;
		cin >>s>>t;
		for (long long i=0;i<v[s].size();i++){
			for (long long j=0;j<v[t].size();j++){
				ans=min(ans,dis[v[s][i].u-m][v[t][j].u-m]+v[s][i].v+v[t][j].v);
			}
		}
		cout <<ans+w[s]+w[t]<<'\n';
	}
	return 0;
}
