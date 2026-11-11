#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,_,q,a,t,x,y,i,j,k,w[500005],d[505][505];
vector<pair<int,int> >v[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>_>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	memset(d,0x3f,sizeof d);
	for(i=1;i<=n;i++){
		d[i][i]=0;
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>a>>t;
			v[a].emplace_back(i,t);
		}
	}
	for(i=1;i<=m;i++)for(auto j:v[i])for(auto k:v[i])if(j.first!=k.first)d[j.first][k.first]=min(d[j.first][k.first],j.second+k.second);
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		cin>>x>>y;
		t=LLONG_MAX;
		for(auto i:v[x])for(auto j:v[y])t=min(t,w[x]+w[y]+i.second+j.second+d[i.first][j.first]);
		cout<<t<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
