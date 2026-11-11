#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[1000010],k[1000010],dis[1010][1010];
vector<int>V[1000010];
vector<pair<int,int> >v[500010];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int si=v[i].size();
		for(int j=0;j<si;j++){
			for(int k=0;k<j;k++){
				dis[v[i][j].first][v[i][k].first]=min(dis[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
				dis[v[i][k].first][v[i][j].first]=dis[v[i][j].first][v[i][k].first];
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
	while(q--){
		int a,b,ans=1e18;
		cin>>a>>b;
		for(auto p:v[a]){
			for(auto q:v[b]){
				ans=min(ans,dis[p.first][q.first]+p.second+q.second);
			}
		}
		cout<<ans+w[a]+w[b]<<'\n';
	}
}
