#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
#define M 510
int n,m,Q;
int w[N],f[M][M];
vector<int>b[N],bt[N];
signed main(){
	int i,j,x,y,k;
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>Q>>Q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>x>>y;
			b[x].push_back(i);
			bt[x].push_back(y);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(i=1;i<=n;i++)f[i][i]=0;
	for(i=1;i<=m;i++)
		for(j=0;j<(int)b[i].size();j++)
			for(k=j+1;k<(int)b[i].size();k++){
				x=b[i][j],y=b[i][k];
				f[x][y]=f[y][x]=min(f[x][y],bt[i][j]+bt[i][k]);
			}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++){
			if(i==k)continue;
			for(j=1;j<=n;j++){
				if(j==i||j==k)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	while(Q--){
		int ans=1e18;
		cin>>x>>y;
		for(i=0;i<(int)b[x].size();i++)for(j=0;j<(int)b[y].size();j++)ans=min(ans,bt[x][i]+f[b[x][i]][b[y][j]]+bt[y][j]);
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
} 
