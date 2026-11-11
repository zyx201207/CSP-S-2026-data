#include<bits/stdc++.h>
using namespace std;
long long dp[500005];
int v[500005];
int a[9999][9999];
int t[9999][9999];
int o[505];
int b[100005][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>o[i];
		for(int j=1;j<=o[i];j++){
			cin>>a[i][j]>>t[i][j];
			b[a[i][j]][i]=1;
		}
	}
	while(q--){
		for(int i=1;i<=m;i++){
			dp[i]=999999999999999;
		}
		int r,w;
		cin>>r>>w;
		dp[r]=v[r];
		while(dp[w]!=999999999999999){
			for(int i=1;i<=n;i++){
				for(int oo=1;oo<=m;oo++){
						if(dp[oo]!=999999999999999&&b[oo][w]==1){
						for(int j=1;j<=o[i];j++){
							dp[j]=min(dp[oo]+t[i][oo]+t[i][j],dp[j]);
						}
					}
				}	
			}
		}
		cout<<dp[w]<<"\n";
	}
	return 0; 
}
