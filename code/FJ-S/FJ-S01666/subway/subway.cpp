#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll N=505,M=500005;
ll c,n,m,d,q,w[M],dis[N][N];
vector<pll> H[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin >>w[i];
	for(int i=1;i<=n;i++){
		ll ki;
		cin >>ki;
		for(int j=1;j<=ki;j++){
			ll ai,ti;
			cin >>ai>>ti;
			H[ai].push_back({i,ti});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)H[i].size();j++){
			for(int k=0;k<(int)H[i].size();k++){
				if(j==k)continue;
				ll x=H[i][j].first,y=H[i][k].first;
				ll w1=H[i][j].second,w2=H[i][k].second;
				dis[x][y]=min(dis[x][y],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int xi,yi;
		cin >>xi>>yi;
		ll ans=1e18;
		for(int i=0;i<(int)H[xi].size();i++){
			for(int j=0;j<(int)H[yi].size();j++){
				ll x=H[xi][i].first,y=H[yi][j].first;
				ll w1=H[xi][i].second,w2=H[yi][j].second;
				ans=min(ans,w[xi]+w[yi]+w1+w2+dis[x][y]);
			}
		}
		cout <<ans<<"\n";
	}
}
