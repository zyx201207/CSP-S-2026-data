#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;long long inf=1e18;
int _,n,m,d,q;
int w[M],cnt[M],id[M][22],t[M][22];
long long dis[N][N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	system("fc subway7.ans subway.out");return 0; 
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int aa,tt;cin>>aa>>tt;
			cnt[aa]++,id[aa][cnt[aa]]=i,t[aa][cnt[aa]]=tt;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++)for(int k=j+1;k<=cnt[i];k++){
			long long tt=t[i][j]+t[i][k];
			dis[id[i][j]][id[i][k]]=min(dis[id[i][j]][id[i][k]],tt);
			dis[id[i][k]][id[i][j]]=min(dis[id[i][k]][id[i][j]],tt);
		}
	}
	for(int i=1;i<=n;i++)for(int k=1;k<=n;k++)for(int j=1;j<=n;j++){
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
	}
	while(q--){
		int x,y;cin>>x>>y;
		long long ans=inf;
		for(int i=1;i<=cnt[x];i++)for(int j=1;j<=cnt[y];j++){
			ans=min(ans,dis[id[x][i]][id[y][j]]+w[x]+w[y]+t[x][i]+t[y][j]);
		}
		cout<<ans<<'\n';
	}
} 
