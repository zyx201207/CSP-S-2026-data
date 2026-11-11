#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
long long l=1,r,ans;
long long sum[500001];
bool check(long long mid){
	for(int i=mid;i<=n;i++)
		if(sum[i]-sum[i-mid]+m>=mid*a[i])return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	r=n,sum[0]=0,ans=(l+r)/2;
	sort(a,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	while(ans>0&&l<r){
		ans=(l+r)/2;
		if(check((l+r)/2))l=ans+1;
		else r=ans-1;
	}
	cout<<ans;
	return 0;
}
