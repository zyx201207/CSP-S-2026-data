#include <bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q,dp[502][502],a[502][502],t,x,y,p=1,minl=1e9,aa,bb,w[1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=1e9;
			dp[j][i]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>t;
		p=m*(i-1)+1;
		for(int j=1;j<=t;j++){
			cin>>x>>y;
			a[i][x]=y;
			dp[p][x]=0;
			dp[x][p]=0;
			p=x;
		}
	}
	while(cin>>aa>>bb){
		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=m;k++){
				dp[k+m*(i-1)][k+m*(j-1)]=a[i][k]+a[j][k];
				dp[k+m*(j-1)][k+m*(i-1)]=a[i][k]+a[j][k];
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			for(int k=1;k<=n*m;k++){
				if(i==j || i==k || j==k) continue;
				dp[i][i]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			minl=min(minl,dp[aa+m*(i-1)][bb+m*(j-1)]+a[i][aa]+a[j][bb]);
		}
	}
	cout<<minl+w[aa]+w[bb];
	minl=1e9;
	}
	return 0;
}
