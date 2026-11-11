#include<bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
int dp[2005][2005]={INF};
int way[2005][2005]={0};
vector<int> ans;
int abs(int a,int b){
	return (a>b)?(a-b):(b-a);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d,c,t;
	cin>>c;
	cin>>t;
	int tt=t;
	while(tt--){
	
		vector<int> land;
		//输入 
		for(int i=0;i<n;i++){
			int tmp=0;
			cin>>tmp;
			land.push_back(tmp);
		}
		//计算dp
		for(int i=0;i<n;i++){
			for(int j=1;j<n;j++){
				if(d>=abs(land[j]-land[i])) dp[i][j]=dp[i][j-1]+1;
			}
		}
		
		
		//二周目 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=1;k<=j-i && d>=abs(land[j]-land[j-k]);k++){
					if(dp[i][j] == dp[i][j-k]+dp[j-k][j]) way[i][j]++;
					if(dp[i][j]>dp[i][j-k]+dp[j-k][j]) dp[i][j] = dp[i][j-k]+dp[j-k][j];
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(way[i][j] == 2) ans[t-tt]++;
			}
		}
	}
	cout<<ans[0]/2;
	for(int i=1;i<t;i++) cout<<'\n'<<ans[i]/2;
	return 0;
}
