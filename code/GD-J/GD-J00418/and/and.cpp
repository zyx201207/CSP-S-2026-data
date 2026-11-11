#include<bits/stdc++.h>

using namespace std;

int n,m;


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n+1); 
	vector<vector<int> > dp(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int am=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i!=j){
				dp[i][j]=(a[i]&a[j]);
			}
			if(dp[i][j]>am&&i==n){
				am=dp[i][j];
			}
		}
	}
	cout<<am;
	return 0;
}
