#include <bits/stdc++.h>
using namespace std;
const long long int INF=9999999999999999;
int n,m,c,d,q;
int w[500005];
int t[505][500005];
int bl[500005][22];
int cnt[500005];
int k;
long long e[505][505];
int ru[505][505];
int chu[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=INF;
		}
		e[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			bl[a][++cnt[a]]=i;
			cin>>t[i][a];
			//cout<<a<<" "<<cnt[a]<<endl;
		}
	}
	for(int i=1;i<=m;i++){
		sort(bl[i]+1,bl[i]+cnt[i]+1);
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=cnt[i];j++){
//			cout<<bl[i][j]<<" ";
//		}
//	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<cnt[k];i++){
			for(int j=i+1;j<=cnt[k];j++){
				if(1ll*t[bl[k][j]][k] + 1ll*t[bl[k][i]][k] < e[bl[k][i]][bl[k][j]]){
					
					e[bl[k][i]][bl[k][j]] = 1ll*t[bl[k][j]][k] + 1ll*t[bl[k][i]][k];
					
					e[bl[k][j]][bl[k][i]] = 1ll*t[bl[k][j]][k] + 1ll*t[bl[k][i]][k];
					
					ru[bl[k][i]][bl[k][j]]=k;
					chu[bl[k][i]][bl[k][j]]=k;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<e[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(e[i][k]!=INF && e[k][j]!=INF && e[i][k]>=0&& e[k][j]>=0)
				e[i][j]=min(e[i][j], e[i][k] + e[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<e[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		long long ans=INF;
		int xx=0;
		int yy=0;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				if(ans>e[bl[x][i]][bl[y][j]]){
					ans=e[bl[x][i]][bl[y][j]];
					xx=bl[x][i];
					yy=bl[y][j];
				}
			}
		}
		if(x!=ru[xx][yy])ans+=1ll*t[xx][x];
		if(y!=chu[xx][yy])ans+=1ll*t[yy][y];
		ans+=1ll*w[x]+1ll*w[y];
		printf("%lld\n",ans);
	}
}
