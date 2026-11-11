#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,p,w[20005],k,a[20005],t[20005],dp[20005][20005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=(1ll<<60);
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int j=1;j<=n;j++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
			for(int s=1;s<i;s++){
				dp[a[s]][a[i]]=dp[a[i]][a[s]]=t[s]+t[i];
			}
		}
	}
	for(int q=1;q<=m;q++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dp[i][q]==(1LL<<60)||dp[q][j]==(1LL<<60)) continue;
				dp[i][j]=min(dp[i][j],dp[i][q]+dp[q][j]);
			}
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
