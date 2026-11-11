#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q,z,aa,gs,dx,dy,aaa,bbb;
ll w[500005],tt,dp[1005][1005],ans,dz;
struct Node {
	int idx;
	ll cd;
};
vector<Node> st[500005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
		cin>>w[i];
	memset(dp,-1,sizeof dp);
	for(int i=1; i<=n; i++) {
		dp[i][i]=0;
		cin>>z;
		for(int j=0; j<z; j++) {
			cin>>aa>>tt;
			st[aa].push_back({i,tt});
		}
	}
	for(int i=1; i<=m; i++) {
		gs=st[i].size();
		for(int j=0; j<gs; j++)
			for(int k=0; k<gs; k++)
				if(k!=j) {
					dx=st[i][j].idx,dy=st[i][k].idx,dz=st[i][j].cd+st[i][k].cd;
					if(dp[dx][dy]==-1)
						dp[dx][dy]=dp[dy][dx]=dz;
					else
						dp[dx][dy]=dp[dy][dx]=min(dp[dx][dy],dz);
				}
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(k!=i&&k!=j&&i!=j) {
					if(!(dp[i][k]!=-1&&dp[k][j]!=-1))
						continue;
					if(dp[i][j]!=-1)
						dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
					else
						dp[i][j]=dp[i][k]+dp[k][j];
				}
	while(q--) {
		ans=5e18;
		cin>>dx>>dy;
		aaa=st[dx].size(),bbb=st[dy].size();
		for(int i=0; i<aaa; i++)
			for(int j=0; j<bbb; j++)
				ans=min(ans,dp[st[dx][i].idx][st[dy][j].idx]+st[dx][i].cd+st[dy][j].cd);
		cout<<ans+w[dx]+w[dy]<<'\n';
	}
	return 0;
}

