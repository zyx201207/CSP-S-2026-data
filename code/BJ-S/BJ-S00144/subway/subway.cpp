#include<bits/stdc++.h>
#define int long long
#define N 500010
#define M 510
#define K 25
using namespace std;
const int inf=(int)1e18;
int c,n,m,d,q,w[N],a[N],t[N],o[N],dis[M][M];
pair<int,int>v[N][K];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			v[a[j]][++o[a[j]]]=make_pair(i,t[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<o[i];j++){
			pair<int,int>now1=v[i][j];
			for(int k=j+1;k<=o[i];k++){
				pair<int,int>now2=v[i][k];
				int x=now1.first,y=now2.first;
				dis[x][y]=dis[y][x]=min(dis[x][y],now1.second+now2.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(int i=1;i<=o[x];i++){
			pair<int,int>now1=v[x][i];
			for(int j=1;j<=o[y];j++){
				pair<int,int>now2=v[y][j];
				ans=min(ans,dis[now1.first][now2.first]+now1.second+now2.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}