#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn,a[500005],d[500005],dp[500005];
bool flag_a,flag_b;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
		if(a[i]!=a[i-1]&&i!=1) flag_a=1;
		if(d[i]!=d[i-1]&&i!=1) flag_b=1;
	}
	if(!flag_a) {
		cout<<n;
		return 0;
	}
	if(!flag_b){
		int num=0,i=1;
		while(num<=m){
			num+=i*d[1];
			i++;
		}
		cout<<i-1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[j]=a[i]-a[j];
		}
		sort(dp+1,dp+1+i);
		long long num=0,cnt=1;
		while(num<=m&&cnt<=i){
			num+=dp[cnt];
			cnt++;
		}
		maxn=max(maxn,cnt-1);
	}
	cout<<maxn;
	return 0;
}
