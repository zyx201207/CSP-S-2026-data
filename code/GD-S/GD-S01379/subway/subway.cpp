#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,ans;
int w[501010],k[501];
int len[501][501];
int cost[501010][21];
int name[501010][21];
int sum[501010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cin>>c>>n>>m>>d>>q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		//cin>>w[i];
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		//cin>>k[i];
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			int a,t;
			//cin>>a>>t;
			scanf("%lld%lld",&a,&t);
			name[a][++sum[a]]=i;
			cost[a][sum[a]]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			len[i][j]=len[j][i]=5e16;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=sum[i];j++){
			for(int k=j+1;k<=sum[i];k++){
				int u=name[i][j],v=name[i][k];
				len[u][v]=len[v][u]=min(len[u][v],cost[i][j]+cost[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(len[i][k]==5e16||len[k][j]==5e16)continue;
				len[i][j]=len[j][i]=min(len[i][j],len[i][k]+len[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		ans=1e18;
		for(int j=1;j<=sum[x];j++){
			for(int k=1;k<=sum[y];k++){
				int u=name[x][j],v=name[y][k];
				ans=min(ans,cost[x][j]+cost[y][k]+len[u][v]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
		//cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
