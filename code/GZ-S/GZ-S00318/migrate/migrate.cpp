#include<bits/stdc++.h>

using namespace std;
int c,t;
long dp[1000];
int n,d;
int sum,cnt;
int main(){
	//GZ-S00318,安顺市第一高级中学，朱兴旺
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
    for(int i=1;i<=t;i++){
    	cin>>n>>d;
    	for(int j=1;j<=n;j++){
		     cin>>dp[i];
	}

	}
	for(int i=1;i<=n;i++){
		if(dp[i]%2==0) sum=n/2;
		if(dp[i]%2!=0) cnt=n%2;
	}
	cout<<sum<<'\n'<<cnt<<'\n';
	fcolse(stdin);
	fclose(stdout);
	return 0;
}
