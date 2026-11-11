#include<bits/stdc++.h>
using namespace std;
//#define int long long

int c,m,n,d,q,w[500055],a,t,bu[1005][1005],dp[1005][1005];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			bu[i][j]=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			bu[i][a]=t;
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				bu[i][j]=min(bu[i][j],bu[i][k]+bu[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<bu[x][y]<<'\n';
	}
	return 0;
}
