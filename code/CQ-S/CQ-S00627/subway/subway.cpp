#include <bits/stdc++.h> 
using namespace std;
int n,m,d,q;
int w[500005];
long long dp[505][505],ans;
int mms[500005][22],hf[500005][22],sl[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)dp[i][j]=1e17;
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k,v,w;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			sl[v]++,mms[v][sl[v]]=i,hf[v][sl[v]]=w;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1,x;j<sl[i];j++){
			x=mms[i][j];
			for(int k=j+1,y;k<=sl[i];k++){
				y=mms[i][k];
				dp[x][y]=min(dp[x][y],1ll*(hf[i][j]+hf[i][k])),dp[y][x]=min(dp[y][x],1ll*(hf[i][j]+hf[i][k]));
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;ans=1e17;
		for(int j=1;j<=sl[x];j++){
			for(int k=1;k<=sl[y];k++){
				ans=min(ans,dp[mms[x][j]][mms[y][k]]+hf[x][j]+hf[y][k]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
