#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],t[500005][505];
long long dp[505][505];
vector<int>fath[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int  i=1;i<=n;i++){
		cin>>k[i];
		for(int  j=1;j<=k[i];j++){
			int  p;
			cin>>p;
			fath[p].push_back(i);
			cin>>t[p][i];
		}
	}
	for(int  i=1;i<=m;i++){
		if(fath[i].size()>1){
	//		cout<<i<<endl;
			for(int  j=0;j<fath[i].size();j++){
				for(int  k=j+1;k<fath[i].size();k++){
					dp[fath[i][j]][fath[i][k]]=t[i][fath[i][j]]+t[i][fath[i][k]];
					dp[fath[i][k]][fath[i][j]]=t[i][fath[i][j]]+t[i][fath[i][k]];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int  k=1;k<=n;k++){
			if(dp[i][k]==1061109567){
				continue;
			}
			for(int  j=1;j<=n;j++){
				if(i==j){
					dp[i][j]=0;
				}
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
//	cout<<dp[1][2];
	for(int i=1;i<=q;i++){
		int x,y;
		long long ans=2147483647;
		cin>>x>>y;
		for(int  j=0;j<fath[x].size();j++){
			for(int k=0;k<fath[y].size();k++){
				if(ans==2147483647){
					ans=(long long)((long long)t[x][fath[x][j]]+(long long)t[y][fath[y][k]]+(long long)dp[fath[x][j]][fath[y][k]]);
				}
				ans=min(ans,(long long)((long long)t[x][fath[x][j]]+(long long)t[y][fath[y][k]]+(long long)dp[fath[x][j]][fath[y][k]]));
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	} 
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
