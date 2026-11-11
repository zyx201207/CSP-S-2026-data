#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+1,N=501;
int c,n,m,d,q,w[M],a[M][21],t[M][21],cnt[M];
ll f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(f,0x3f,sizeof f);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,x,w,k;i<=n;i++){
		cin>>k;
		f[i][i]=0;
		while(k--){
			cin>>x>>w;
			a[x][++cnt[x]]=i;
			t[x][cnt[x]]=w;
		}
	}
	for(int i=1;i<=m;i++){
		for(int x=1;x<=cnt[i];x++)
		for(int y=x+1;y<=cnt[i];y++){
			int u=a[i][x],wu=t[i][x];
			int v=a[i][y],wv=t[i][y];
			f[u][v]=f[v][u]=min(f[u][v],1ll*wu+wv);
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	
	while(q--){
		ll x,y,ans=4e18;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];i++)
		for(int j=1;j<=cnt[y];j++){
			int u=a[x][i],wu=t[x][i];
			int v=a[y][j],wv=t[y][j];
			ans=min(ans,f[u][v]+wu+wv+w[x]+w[y]);
		}
		cout<<ans<<'\n';
	}
}
