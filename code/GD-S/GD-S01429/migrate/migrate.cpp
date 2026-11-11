#include<bits/stdc++.h>
using namespace std;
int c,t,ans;
int dfs(int x,int y,int d){
	int dp[2000010];
	for(int i=x+1;i<=y;i++){
		
	}
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>t;
	while(t--){
		long long n,d,a[2000010];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				cout<<dfs(i,j,d)<<endl;
			}
		}
	}
	return 0;
} 
