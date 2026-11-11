#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool check(long long mid){
	long long sum=0;
	for(int i=1;i<mid;i++)sum+=(a[mid]-a[i]); 
	for(int i=mid+1;i<=n;i++){
		if(sum<=m)return 1;
		sum=sum-(a[i-1]-a[i-1-mid])+(mid-1)*(a[i]-a[i-1]);
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r<<'\n';
	return 0;
}
