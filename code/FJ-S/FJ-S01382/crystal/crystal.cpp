#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ma,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
		if(sum[i]<=m)ma=i;		
	}
	for(int i=ma;i<=n;i++){
		for(int j=i-ma+1;j>=1;j--){
			if(sum[i]-sum[j]<=m)ans=max(ans,1LL*i-j+1);
			else break;
		}
	}
	cout<<ans;
	return 0;
}
