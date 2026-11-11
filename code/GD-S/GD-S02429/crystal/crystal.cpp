#include <bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		//cout<<(m>=a[i]*(i-1)-sum[i-1]);
		if(m>=a[i]*(i-1)-sum[i-1]){
			cnt=i;
			
		}
	}
	//cout<<a[315275]*(315275-1)<<" "<<sum[315275-1]+m<<" ";
	//cout<<(m>=a[315275]*(315275-1)-sum[315275-1])<<" ";
	if (cnt>1) cout<<cnt;
	else cout<<1;
	return 0;
} 
