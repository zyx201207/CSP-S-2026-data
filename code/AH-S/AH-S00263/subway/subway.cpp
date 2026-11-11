#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
int c,n,m,d,q;
int p[500010];
struct nd{
	int l,tm;
};
nd t[500010][50];
int size[500010];
int ed[510][510],dis[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>p[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,tm;
	    	cin>>a>>tm;
	    	t[a][++size[a]]={i,tm};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ed[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++) ed[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=size[i]-1;j++){
			for(int k=j+1;k<=size[i];k++){
				int lj=t[i][j].l,tmj=t[i][j].tm;
				int lk=t[i][k].l,tmk=t[i][k].tm;
				ed[lj][lk]=min(ed[lj][lk],tmj+tmk);
				ed[lk][lj]=ed[lj][lk];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=ed[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				dis[x][y]=min(dis[x][k]+dis[k][y],dis[x][y]);
			}
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		int ans=INF;
		for(int i=1;i<=size[s];i++){
			for(int j=1;j<=size[e];j++){
				int li=t[s][i].l,tmi=t[s][i].tm;
				int lj=t[e][j].l,tmj=t[e][j].tm;
				ans=min(ans,dis[li][lj]+p[s]+p[e]+tmi+tmj);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
