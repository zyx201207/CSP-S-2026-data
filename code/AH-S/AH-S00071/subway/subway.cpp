#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5+10,M=5e2+10;
vector<pair<int,long long>>G[N];
long long w[N],mp[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x;long long y;cin>>x>>y;
			G[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[i][j]=(i==j?0:1e16);
	for(int i=1;i<=m;i++) for(auto j:G[i]) for(auto k:G[i])
		mp[j.first][k.first]=mp[k.first][j.first]=min(mp[j.first][k.first],j.second+k.second);
	/*for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cout<<i<<" "<<j<<" "<<mp[i][j]<<'\n';*/
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(mp[i][k]+mp[j][k]<mp[i][j]) mp[i][j]=mp[j][i]=mp[i][k]+mp[j][k];
	/*for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cout<<i<<" "<<j<<" "<<mp[i][j]<<'\n';*/
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;long long ans=1e18;
		for(auto i:G[x]) for(auto j:G[y])
			ans=min(ans,1ll*i.second+j.second+mp[i.first][j.first]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
