#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int c,n,m,d,q,w[500010],ans[1010][1010];
signed main(){		
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int x,xx,y,yy;
		cin>>x>>xx>>y>>yy;
		ans[x][y]=xx+yy;
		ans[y][x]=xx+yy;
	}
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=1;k<=m;k++){
				ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}