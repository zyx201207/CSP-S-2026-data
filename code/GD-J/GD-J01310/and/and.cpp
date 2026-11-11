#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		long long ma=-1;
		for(int i=1;i<=n;i++)ma=ma>a[i]?ma:a[i];
		cout<<ma<<endl;
		return 0;
	}else if(m==n){
		long long num=a[1];
		for(int i=2;i<=n;i++)num=num&a[i];
		cout<<num<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=200000;j++)dp[j]=a[i];
		for(int j=m;j>i;j--){
			dp[j]=max(dp[j-1],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
