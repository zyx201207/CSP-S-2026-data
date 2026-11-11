#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
namespace CSPS{
	int c,n,m,d,q;
	int w[500005];
	long long dis[505][505];
	pair<int,int> s[500005][25];
	int cnt[500005];
	void solve(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=LONG_LONG_MAX;
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			while(k--){
				int a,t;
				cin>>a>>t;
				s[a][++cnt[a]]={i,t};
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=cnt[i];j++){
				for(int k=1;k<=cnt[i];k++){
					dis[s[i][j].first][s[i][k].first]=min(dis[s[i][j].first][s[i][k].first],1ll*s[i][j].second+s[i][k].second);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]==LONG_LONG_MAX||dis[k][j]==LONG_LONG_MAX)continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			long long ans=LONG_LONG_MAX;
			for(int i=1;i<=cnt[x];i++){
				for(int j=1;j<=cnt[y];j++){
					ans=min(ans,dis[s[x][i].first][s[y][j].first]+s[x][i].second+s[y][j].second);
				}
			}
			cout<<ans+w[x]+w[y]<<endl;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int Q=1;
//	cin>>Q;
	while(Q--)CSPS::solve();
//while(1);
	return 0;
}
/*
总步行时间啊，我还以为是啥呢……
首先每次暴力跑Floyd。
回（追）忆Floyd的警示后人。
好的200pts了。
1s 1024MB
0.8s 104MB
*/

