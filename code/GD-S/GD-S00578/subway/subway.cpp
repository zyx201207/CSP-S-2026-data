#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g[10001];
int w[10001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int to,t;
			cin>>to>>t;
			g[i].push_back({to,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<g[x][y].second+g[y][x].second;
	}
}
