#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],w[N],k[N],c,d,n,m,q,ans=0;
int dx[510][510];
vector<pair<int,int> > in[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dx,0x3f,sizeof(dx));
	for (int i=1;i<=m;i++)cin>>w[i];
	for (int i=1;i<=n;i++){
		dx[i][i]=0;
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			int y,v;
			cin>>y>>v;
			for (auto l:in[y]){
				int nx=l.first,ny=l.second;
				if (v+ny<dx[nx][i])dx[nx][i]=dx[i][nx]=v+ny;
			}
			in[y].push_back(make_pair(i,v));
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (dx[i][k]+dx[k][j]<dx[i][j])
					dx[i][j]=dx[i][k]+dx[k][j];
			}
		}
	}
	while (q--){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		for (auto i:in[x]){
			for (auto j:in[y]){
					int nx=i.first,ny=j.first;
					ans=min(ans,dx[nx][ny]+i.second+j.second);
				}
		}
		cout<<ans+w[x]+w[y]<<'\n';
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
