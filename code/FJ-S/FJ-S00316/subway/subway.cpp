#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=505,M=5e5+5,inf=pow(2,60);
int c,n,m,d,q,f[N][N],w[M];
vector <int> a[M],t[M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) f[i][j]=inf;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		int k,x,y;cin>>k;f[i][i]=0;
		for(int j=1;j<=k;j++) {
			cin>>x>>y;a[x].push_back(i);t[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++)
		for(int x=0;x<a[i].size();x++)
			for(int y=0;y<a[i].size();y++){
				if(x==y) continue;
				f[a[i][x]][a[i][y]]=min(f[a[i][x]][a[i][y]],t[i][x]+t[i][y]);
			}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y,ans=inf;cin>>x>>y;
		for(int i=0;i<a[x].size();i++)
			for(int j=0;j<a[y].size();j++)
				ans=min(ans,f[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}

