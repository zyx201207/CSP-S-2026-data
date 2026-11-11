#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

//d为地铁线路之间的换乘时间，lin为地铁站连接的线路，tim为站厅到每一个站台的时间 
ll d[505][505],lin[500005][25],tim[500005][25];
ll c,n,m,dd,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f3f3f3f,sizeof(d));
	cin>>c>>n>>m>>dd>>q;
	for(ll i=1;i<=m;i++){
		cin>>tim[i][0];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			lin[a][0]++;
			lin[a][lin[a][0]]=i;
			tim[a][lin[a][0]]=t;
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll x=1;x<lin[i][0];x++){
			for(ll y=x+1;y<=lin[i][0];y++){
				d[lin[i][x]][lin[i][y]]=min(tim[i][x]+tim[i][y],d[lin[i][x]][lin[i][y]]);
				d[lin[i][y]][lin[i][x]]=d[lin[i][x]][lin[i][y]];
			}
		}
	}
	for(ll i=1;i<=n;i++) d[i][i]=0;
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				d[j][i]=d[i][j];
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		ll ans=1e17;
		for(ll a=1;a<=lin[x][0];a++){
			for(ll b=1;b<=lin[y][0];b++){
				ans=min(ans,d[lin[x][a]][lin[y][b]]+tim[x][a]+tim[y][b]);
			}
		}
		ans+=tim[x][0]+tim[y][0];
		cout<<ans<<"\n";
	}
}
