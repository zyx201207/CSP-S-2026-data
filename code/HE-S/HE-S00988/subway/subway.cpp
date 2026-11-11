#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,n,m,d,q;
int w[N],k[N],a[N][N],t[N][N],dp[N][N];
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		memset(a,0,sizeof(a));
		memset(t,0x3f,sizeof(t));
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	while(q--){
		cin>>x>>y;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dp[i][j]=min(dp[i][j],t[i][k]+t[k][j]);
				}
			} 
		}	
		cout<<dp[x][y]+w[x]+w[y];							
	} 
	
	
	return 0;
}
