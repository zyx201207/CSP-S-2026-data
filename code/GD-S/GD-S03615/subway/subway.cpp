#include <bits/stdc++.h>
using namespace std;
#define int long long
int csd,n,m,d,q,sz[505],tim[500010],ans,g[505][505];
vector<pair<int,int>> v[500010];
int rd() {
	int res=0,num[20],z=0;char c;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return res;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	csd=rd(),m=rd(),n=rd(),d=rd(),q=rd();
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++) cin>>tim[i];
	for(int i=1;i<=m;i++) {
		sz[i]=rd(),g[i][i]=0;
		for(int j=1,x,y;j<=sz[i];j++) x=rd(),y=rd(),v[x].push_back({i,y});
	}
	for(int i=1;i<=n;i++) for(auto j:v[i]) for(auto k:v[i])
		if(j.first!=k.first) g[j.first][k.first]=j.second+k.second;
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1,x,y;i<=q;i++) {
		x=rd(),y=rd();
		int ans=1e18;
		for(auto j:v[x]) for(auto k:v[y]) ans=min(ans,g[j.first][k.first]+j.second+k.second);
		cout<<ans+tim[x]+tim[y]<<endl;
	}
	return 0;
}
