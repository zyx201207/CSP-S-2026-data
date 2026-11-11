#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],f[510][510];
vector<pair<int,int>>v[500010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=1e18;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int x,y,z;cin>>x;
		for(int j=1;j<=x;j++)cin>>y>>z,v[y].push_back({i,z});
	}
	for(int i=1;i<=m;i++){
		int s=v[i].size();
		for(int j=0;j<s;j++){
			for(int k=j+1;k<s;k++){
				int a=v[i][j].first,b=v[i][k].first,aa=v[i][j].second,bb=v[i][k].second;
				f[a][b]=min(f[a][b],aa+bb);f[b][a]=min(f[b][a],aa+bb);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i)continue;
			for(int j=1;j<=n;j++){
				if(j==i||j==k)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=1e18;cin>>x>>y;
		int s1=v[x].size(),s2=v[y].size();
		for(int j=0;j<s1;j++){
			for(int k=0;k<s2;k++){
				int a=v[x][j].first,b=v[y][k].first,aa=v[x][j].second,bb=v[y][k].second;
				ans=min(ans,aa+f[a][b]+bb);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
