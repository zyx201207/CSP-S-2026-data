#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500010],dis[510][510];
vector<int>h[500010],t[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			h[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<(int)h[i].size();j++)
			for(int k=0;k<(int)h[i].size();k++)
				dis[h[i][j]][h[i][k]]=min(dis[h[i][j]][h[i][k]],t[i][j]+t[i][k]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int l,r,ans=1e18;
		cin>>l>>r;
		for(int i=0;i<(int)h[l].size();i++)
			for(int j=0;j<(int)h[r].size();j++)
				ans=min(ans,dis[h[l][i]][h[r][j]]+t[l][i]+t[r][j]);
		cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}
