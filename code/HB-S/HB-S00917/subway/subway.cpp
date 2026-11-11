#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[505][5005];
int dp[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	memset(a,-1,sizeof(a));
	memset(dp,INT_MAX,sizeof(dp));
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		vector<int> linee;
		for(int j=0;j<k;j++){
			int x;
			cin>>x;
			linee.push_back(x);
			cin>>a[i][x];
		}
		for(int j=0;j<(int)linee.size();j++){
			for(int k=0;k<(int)linee.size();k++){
				dp[j][k]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){//start
		for(int j=1;j<=m;j++){//end
			if(i==j){
				dp[i][j]=0;
				continue;
			}
			for(int k=1;k<i;k++){//change
				for(int l=1;l<=n;l++){//line
					if(a[l][k]!=-1&&a[l][j]!=-1&&dp[i][k]!=INT_MAX){
						dp[i][j]=min(dp[i][k]+a[l][k]+a[l][j],dp[i][j]);
					}
				}
			}
			
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
//{%$~~`#@$%#^&*%$&^#$%&%^}
