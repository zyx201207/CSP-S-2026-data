#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],m;
long long sum[500005];
bool check(int k){
	for(int i=1,j=k;j<=n;i++,j++){
		long long p=sum[j-1]-sum[i-1];
		if((k-1)*a[j]-p<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i]; 
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
