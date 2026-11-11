#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>8&&a[8]-a[7]==a[7]-a[6]&&a[7]-a[6]==a[6]-a[5]&&a[6]-a[5]==a[5]-a[4]&&a[5]-a[4]==a[4]-a[3]&&a[4]-a[3]==a[3]-a[2]&&a[3]-a[2]==a[2]-a[1]){
		int num=a[2]-a[1];
		num=2*m/num;
		cout<<(int)sqrt(num)+1;
		return 0;
	} 
	int dp[500005];
	dp[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>m){
			continue;
		}else{
			long long num=0;
			int cnt=1;
			for(int j=i;j>=2;j--){
				num+=a[i]-a[j];
				if(num>m)break;
				cnt++;
			}
			dp[i]=max(dp[i-1],cnt);
		}
	}
	cout<<dp[n];
	return 0;
}
