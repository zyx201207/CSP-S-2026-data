#include<bits/stdc++.h>

using namespace std;

long long c,n,m,d,q,w[500005],k[505],A[505][505];
vector<pair<int,long long> >E[500005];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			int x,y;
			cin>>x>>y,E[x].push_back({i,y});
		}
	}
	memset(A,0x3f,sizeof A);
	for(int i=1;i<=n;i++) A[i][i]=0;
	for(int i=1;i<=m;i++) for(int j=0;j<(int)E[i].size();j++) for(int k=j+1;k<(int)E[i].size();k++) A[E[i][j].first][E[i][k].first]=A[E[i][k].first][E[i][j].first]=min(A[E[i][j].first][E[i][k].first],E[i][j].second+E[i][k].second);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
	while(q--) {
		long long x,y,ans=1e18;
		cin>>x>>y;
		for(auto i:E[x]) for(auto j:E[y]) ans=min(ans,A[i.first][j.first]+i.second+j.second);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
