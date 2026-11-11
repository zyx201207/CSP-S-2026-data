#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1007;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
int c,n,m,d,q;
ll dp[N][N],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f3f,sizeof(dp));
	for(int i=1;i<=m;i++) dp[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int>a,t;
		a.push_back(0);t.push_back(0);
		for(int j=1;j<=k;j++){
			int x,w;
			cin>>x>>w;
			a.push_back(x);
			t.push_back(w);
		}
		for(int u=1;u<=k;u++){
			for(int v=u+1;v<=k;v++){
				ll w=t[u]+t[v];
				dp[a[u]][a[v]]=min(dp[a[u]][a[v]],w);
				dp[a[v]][a[u]]=min(dp[a[v]][a[u]],w);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dp[i][k]!=INF&&dp[k][j]!=INF){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dp[x][y]<<"\n";
	}
	return 0;
}
