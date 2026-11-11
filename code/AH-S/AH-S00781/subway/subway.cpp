#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
int head[505],idx;
int c,n,m,d,q,ans;
int w[500005];
int f[505][505];
map<int,int> mp[505];
vector<int> k[500005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof f);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int l,x,y;
		cin>>l;
		while(l--)cin>>x>>y,mp[i][x]=y,k[x].push_back(i);
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<k[i].size();j++){
			for(int l=j+1;l<k[i].size();l++){
				int x=k[i][j],y=k[i][l];
				f[x][y]=f[y][x]=min(f[x][y],mp[x][i]+mp[y][i]);
			}
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
	while(q--){
		int x,y,ans=INF;
		cin>>x>>y;
		for(int i=0;i<k[x].size();i++){
			for(int j=0;j<k[y].size();j++){
				int xx=k[x][i],yy=k[y][j];
				ans=min(ans,f[xx][yy]+mp[xx][x]+mp[yy][y]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
