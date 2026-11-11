#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m;
long long x;
long long sum[500005];
bool check(int mid){
	for(int i=mid;i<=n;i++){
		if(sum[i]-sum[i-mid]+m>=a[i]*mid){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}
		else
			r=mid-1;
	}
	while(check(r)==0)r--;
	cout<<r;
	return 0;
}
/*
5 8
-3 -1 2 2 7
Oct31==Dec25?
*/
