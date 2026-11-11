#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q,w[N],dis[M][M],a[21][N],t[21][N],cnt[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int i=1;i<=n;i++){
		int y;cin>>y;
		for (int j=1;j<=y;j++){
			int x;cin>>x;cnt[x]++;
			a[cnt[x]][x]=i;cin>>t[cnt[x]][x];
			for (int k=1;k<cnt[x];k++){
				dis[i][a[k][x]]=dis[a[k][x]][i]=min(dis[i][a[k][x]],t[k][x]+t[cnt[x]][x]);
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while (q--){
		int x,y,ans=LONG_LONG_MAX;cin>>x>>y;
		for (int i=1;i<=cnt[x];i++){
			for (int j=1;j<=cnt[y];j++){
				ans=min(ans,t[i][x]+dis[a[i][x]][a[j][y]]+t[j][y]);
			}
		}cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
