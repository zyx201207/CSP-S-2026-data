#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
ll c,n,m,d,q;
ll k,a,t,len;
ll dis[510][510],w[500010];
vector<pair<ll,ll> >o[500010];
int main(){
	freopen("subway.in" ,"r",stdin );
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=1e15;
	for(int i=1;i<=n;++i){
		dis[i][i]=0;
		cin>>k;
		while(k--){
			cin>>a>>t;
			o[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;++i){
		len=o[i].size();
		ll L=0;
//		cout<<"in station"<<i<<'\n';
//		cout<<"    "<<len<<"passes";
//		cout<<'\n';
		for(auto&l:o[i]){
			for(int R=L+1;R<len;++R){
				auto&r=o[i][R];
				dis[l.first][r.first]=min(dis[l.first][r.first],l.second+r.second);
				dis[r.first][l.first]=min(dis[r.first][l.first],l.second+r.second);
//				cout<<"    "<<l.first<<" "<<r.first<<"="<<l.second+r.second<<'\n';
			}
			++L;
		}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
	while(q--){
		ll L,R,ans=1e15;
		cin>>L>>R;
		for(auto&l:o[L]){
			for(auto&r:o[R]){
				ans=min(ans,dis[l.first][r.first]+l.second+r.second);
			}
		}
		cout<<ans+w[L]+w[R]<<'\n';
	}
	return 0;
} 
