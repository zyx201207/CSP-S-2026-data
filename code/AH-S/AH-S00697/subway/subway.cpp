#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+10;
const long long oo=1e18;
int c,n,m,d,q,val[M];
vector<pair<int,int> > a[M];
long long f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&val[i]);
	for(int k,i=1;i<=n;i++){
		scanf("%d",&k);
		for(int x,y,j=1;j<=k;j++){
			scanf("%d%d",&x,&y);
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++) 
		    f[i][j]=f[j][i]=oo;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		int len=a[i].size();
	    for(int j=0;j<len;j++)
	        for(int k=j+1;k<len;k++){
			    int u=a[i][j].first,v=a[i][k].first,w=a[i][j].second+a[i][k].second;
	            f[u][v]=f[v][u]=min(f[u][v],1ll*w);
	        }
		}
	for(int k=1;k<=n;k++)
	    for(int i=1;i<=n;i++)
	        for(int j=1;j<=n;j++)
	            f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int u,v,i=1;i<=q;i++){
		scanf("%d%d",&u,&v);
		long long ans=oo;
		int lenu=a[u].size(),lenv=a[v].size();
		for(int j=0;j<lenu;j++)
		    for(int k=0;k<lenv;k++){
			    long long w=a[u][j].second+a[v][k].second;
		        ans=min(ans,w+f[a[u][j].first][a[v][k].first]);
		    }
		printf("%lld\n",ans+val[u]+val[v]);
	}
	return 0;
}

