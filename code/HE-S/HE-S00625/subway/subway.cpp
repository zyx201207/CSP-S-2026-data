#include<bits/stdc++.h>
using namespace std;
const int N=2e4+7,inf=0x3f3f3f3f;
int c,n,m,d,q;
int w[N];
int dp[N][N]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(dp,inf,sizeof(dp));
	int tmp[n+1],t[n+1];
	for(int k,i=1;i<=n;i++){
		for(int a,ta,j=1;j<=k;j++){
			cin>>a>>ta;
			dp[a][a]=0;
			for(int c=1;c<j;c++){
				dp[a][tmp[c]]=ta+t[c];
				dp[tmp[c]][a]=ta+t[c];
			}
			tmp[j]=a;t[j]=ta;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(dp[i][k]==inf)continue;
			for(int j=i+1;j<=m;j++){
				if(dp[k][j]==inf)continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}	
	while(q--){
		int x,y;
		cin>>x>>y; 
		cout<<(w[x]+w[y]+dp[x][y])<<"\n";
	}
	return 0;
} 
