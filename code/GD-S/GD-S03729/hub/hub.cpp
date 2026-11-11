#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500100],a[510][510],t[510][510],k[510],hc[510][510][510],g,h;
vector<pair<int,int> > st[510];
vector<int> z[510];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	for(int i=1; i<=n; i++){
		cin>>k[i];
		for(int j=1; j<=k[i]; j++){
			cin>>a[i][j]>>t[i][j];
			for(int w=0; w<st[a[i][j]].size(); w++){
				int x=st[a[i][j]][w].first;
				int y=st[a[i][j]][w].second;
				hc[i][x][a[i][j]]=y+t[i][j];
			}
			st[a[i][j]].push_back({i,j});
		}
		for(int j=1; j<=k[i]; j++){
			for(int w=j+1; w<=k[i]; w++){
				z[a[i][j]].push_back(a[i][w]);
				z[a[i][w]].push_back(a[i][j]);
			}
		}
	}
	for(int i=1; i<=q; i++){
		cin>>g>>h;
		
	}
	return 0;
}
