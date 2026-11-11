#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q,w[N];
ll f[M][M];
vector<pii>zhan[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(f,0x3f,sizeof f);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;f[i][i]=0;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;scanf("%d%d",&a,&t);
			zhan[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int k=zhan[i].size();
		for(int j=0;j<k;j++){
			int xj=zhan[i][j].first;
			ll uj=zhan[i][j].second;
			for(int l=j+1;l<k;l++){
				int xl=zhan[i][l].first;
				ll ul=zhan[i][l].second;
				f[xj][xl]=f[xl][xj]=min(f[xj][xl],uj+ul);
			}
		}
	}
	for(int o=1;o<=n;o++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][o]+f[o][j]);
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		ll ans=1e18; 
		for(pii o:zhan[x])
			for(pii p:zhan[y])
				ans=min(ans,f[o.first][p.first]+o.second+p.second+w[x]+w[y]);
		printf("%lld\n",ans);
	}
	
	return 0;
} 
