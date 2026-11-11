#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,ac = 0,ac1 = 0;
long long a[5000005],sum[5000005],cnt[5000005],ans1[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		sum[i] = a[n]-a[i];
		ans = ans+sum[i];
	}
	sort(sum+1,sum+1+n);
	for(int i = 1;i<=n;i++){
		cnt[i] = cnt[i-1]+sum[i];
	}
	
	for(int i = n;i>=1;i--){
		ans1[i] = ans-cnt[n-i+1]-(a[n]-a[i])*(i-1);
	}
	for(int i = 1;i<=n;i++){
		if(ans1[i]<=m){
			ac++;
		}
	}
	cout<<ac;
	return 0;
}
