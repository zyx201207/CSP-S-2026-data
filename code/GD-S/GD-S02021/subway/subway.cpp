#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=505,M=5e5+5;
ll w[M];
ll k[N];
vector<ll>a[N];
vector<ll>t[N];
ll dis[N][N];
vector<pair<ll,ll> >v[M];
#define fir first
#define sec second
signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].reserve(k[i]);
		t[i].reserve(k[i]);
		for(int j=1;j<=k[i];j++){
			int a_,t_;
			cin>>a_>>t_;
			a[i].push_back(a_);
			t[i].push_back(t_);
			v[a_].push_back(make_pair(i,t_));
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		
		for(int j=0;j<v[i].size();j++){
			for(int l=0;l<v[i].size();l++){
				if(v[i][j].fir==v[i][l].fir)	continue;
				dis[v[i][l].fir][v[i][j].fir]=dis[v[i][j].fir][v[i][l].fir]
				=min(dis[v[i][j].fir][v[i][l].fir],v[i][j].second+v[i][l].second);
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				dis[j][l]=min(dis[j][l],dis[j][i]+dis[i][l]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,
				dis[v[x][i].fir][v[y][j].fir]+v[x][i].sec+v[y][j].sec);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';	
	}
	
	return 0;
}
