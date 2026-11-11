#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pub push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const int DC=0;
const ll mod=0;
const int N=0;

int _c;
int n,m,d,q;
ll w[500005],dis[505][505];
vector<pair<int,ll>>v[500005];

void INIT(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);}
void SOLVE(){
	cin>>_c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		while(k--){
			int x;ll t;
			cin>>x>>t;
			v[x].pub({i,t});
		}
	}
	for(int i=1;i<=m;i++)for(auto[x,tx]:v[i])for(auto[y,ty]:v[i])
		dis[x][y]=min(dis[x][y],tx+ty);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(auto[a,ta]:v[x])for(auto[b,tb]:v[y])
			ans=min(ans,w[x]+w[y]+ta+tb+dis[a][b]);
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	INIT();
	int T;
	if(DC)cin>>_c>>T;else T=1;
	for(int _=1;_<=T;_++)SOLVE();
	return 0;
}