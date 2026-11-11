#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200000];
int dp[200000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 1;i <= t;i ++){
		cin>>n>>m;
		fill(dp + 1,dp + n + 1,0);
		for(int i = 1;i <= n;i ++){
			cin>>a[i];
		}
		if(a[2] - a[1] > m){
			cout<<0<<'\n';
			continue;
		}else{
			cout<<1<<'\n';
		}
		
	}
}
