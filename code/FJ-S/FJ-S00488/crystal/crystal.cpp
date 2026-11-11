#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long check(int len){
	long long sum=0;
	for(int i=1;i<len;i++){
		sum+=(a[len]-a[i]);
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int mid=l+(r-l)/2;
	while(l<=r){
		mid=l+(r-l)/2;
		long long p=check(mid);
		if(p>m){
			r=mid-1;
		}else if(p<=m){
			l=mid+1;
		}
	}
	cout<<r;
	return 0;
}
