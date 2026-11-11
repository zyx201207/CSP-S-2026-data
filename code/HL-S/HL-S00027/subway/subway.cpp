#include<bits/stdc++.h>
using namespace std;
long long w[500010],k[500010],inf=0x3f3f3f3f3f3f3f3f;
vector<int> v[500010];
vector<long long> v2[500010];
long long dt[510][510];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(dt,0x3f,sizeof(dt));
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			v[a].push_back(i);
			v2[a].push_back(t);
		}
	}
	for (int i=1;i<=n;i++) dt[i][i]=0;
	for (int i=1;i<=m;i++){
		for (int j=0;j<v[i].size();j++){
			for (int k=j+1;k<v[i].size();k++){
				dt[v[i][j]][v[i][k]]=min(dt[v[i][j]][v[i][k]],v2[i][j]+v2[i][k]);
				dt[v[i][k]][v[i][j]]=min(dt[v[i][k]][v[i][j]],v2[i][k]+v2[i][j]);
			}
		}
	}
	for (int p=1;p<=n;p++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dt[i][j]=min(dt[i][j],dt[i][p]+dt[j][p]);
			}
		}
	}
	while (q--){
		int x,y;
		cin>>x>>y;
		long long ans=inf;
		for (int i=0;i<v[x].size();i++){
			for (int j=0;j<v[y].size();j++){
				ans=min(ans,dt[v[x][i]][v[y][j]]+v2[x][i]+v2[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
