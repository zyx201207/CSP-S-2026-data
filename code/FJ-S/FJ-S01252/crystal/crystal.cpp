#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long l=LLONG_MAX,r=LLONG_MIN;
long long ans=0;
bool check(long long midd){
	long long x=0;
	for(long long i=1;i<=n;i++){
		if(a[i]<=midd){
			x+=abs(midd-a[i]);
		}
	}
	return x<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	long long mid=0;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	for(long long i=1;i<=n;i++){
		if(a[i]<=mid){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
