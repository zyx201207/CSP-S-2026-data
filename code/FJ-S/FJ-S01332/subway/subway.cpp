#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
using namespace std;
int c,n,m,d,q,x,y,k,w[500005],dis[505][505],ans;
vector<pair<int,int> > to[500005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> x >> y;
			to[x].pb(mp(i,y));
		}
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto p:to[i]){
			for(auto q:to[i]){
				x=p.ft,y=q.ft;
				dis[x][y]=min(dis[x][y],p.sd+q.sd);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin >> x >> y;
		ans=1e18;
		for(auto p:to[x]){
			for(auto q:to[y]){
				ans=min(ans,p.sd+dis[p.ft][q.ft]+q.sd);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
