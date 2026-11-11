#include<bits/stdc++.h>
//#define int long long
#define Pair pair<int,int>
#define w first
#define tp second
#define infl 1e17
using namespace std;
typedef long long LL;
const int N=510,M=5e5+10;//!!
int nw[M];
vector<Pair> f[M];//which station
LL mp[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>nw[i];
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		while(t--){
			int tp,w;cin>>tp>>w;
			f[tp].push_back({w,i});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j]=infl;
			if(i==j) mp[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int tp1=0;tp1<f[i].size();tp1++){
			int wa=f[i][tp1].w,a=f[i][tp1].tp;
			for(int tp2=tp1+1;tp2<f[i].size();tp2++){
				int wb=f[i][tp2].w,b=f[i][tp2].tp;
				mp[a][b]=min(mp[a][b],1LL*wa+wb);
				mp[b][a]=mp[a][b];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		LL ans=infl;
		LL base=nw[x]+nw[y];
		for(int tp1=0;tp1<f[x].size();tp1++){
			int wa=f[x][tp1].w,a=f[x][tp1].tp;
			for(int tp2=0;tp2<f[y].size();tp2++){
				int wb=f[y][tp2].w,b=f[y][tp2].tp;
				LL res=base+wa+wb+mp[a][b];
				ans=min(ans,res);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
