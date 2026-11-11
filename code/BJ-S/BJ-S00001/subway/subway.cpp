#include<bits/stdc++.h>
using namespace std;
long long w[500005],g[505][505];
vector<pair<long long,long long> >s[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			s[a].push_back({t,i});
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i!=j)g[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)s[i].size()-1;j++){
			for(int l=j+1;l<(int)s[i].size();l++){
				g[s[i][j].second][s[i][l].second]=min(g[s[i][j].second][s[i][l].second],s[i][j].first+s[i][l].first);
				g[s[i][l].second][s[i][j].second]=min(g[s[i][l].second][s[i][j].second],s[i][j].first+s[i][l].first);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				g[j][l]=min(g[j][l],g[j][i]+g[i][l]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long mi=1e18;
		for(int i=0;i<(int)s[x].size();i++){
			for(int j=0;j<(int)s[y].size();j++){
				mi=min(mi,s[x][i].first+s[y][j].first+g[s[x][i].second][s[y][j].second]);
			}
		}
		cout<<mi+w[x]+w[y]<<"\n";
	}
    return 0;
}