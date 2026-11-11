#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[500],a[500][5005],t[500][5005];
int dp[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			dp[a[i][j]][i+m]=t[i][j];
			dp[i+m][a[i][j]]=t[i][j];
			//dp[a[i][j]][a[i][j]]=0;
			//dp[i][a[i][j]]=t[i][j];
		} 
	}
	//for(int v=1;v<=m;v++){
		for(int c=n+m;c>=1;c){
			for(int j1=1;j1<=m;j1++){
				for(int j2=1;j2<=m;j2++){
					dp[j1][j2]=min(dp[j1][c]+dp[j2][c],dp[j1][j2]);
				}
			}
		}
//	}
	
	for(int i=1;i<=q;i++){ 
		int x,y;
		cin>>x>>y;
		int tian=w[x]+w[y];
		tian+=dp[x][y];
		cout<<tian<<endl;
	}
	return 0;
}
/*
0 2 5 20 2 
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/




