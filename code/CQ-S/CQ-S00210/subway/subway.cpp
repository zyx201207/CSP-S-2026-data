#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=5e5+10;
const ll inf=1e16;
ll cas,n,m,d,q,w[M],k[N];
vector<ll> a[N],t[N];
vector<pair<ll,ll> > belong[M];
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>cas>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			belong[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=inf;
	}
	for(int i=1;i<=m;i++){
		ll len=belong[i].size();
		for(int j=0;j<len;j++){
			pair<ll,ll> x=belong[i][j];
			for(int l=j;l<len;l++){
				pair<ll,ll> y=belong[i][l];
				dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
				dis[y.first][x.first]=min(dis[y.first][x.first],x.second+y.second);	
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll x,y,ans=inf;
		cin>>x>>y;
		for(pair<ll,ll> id1:belong[x]){
			for(pair<ll,ll> id2:belong[y]){
				ans=min(ans,id1.second+id2.second+dis[id1.first][id2.first]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
} 
