#include<bits/stdc++.h>
using namespace std;
int n,mx;
long long m;
int a[500010];
long long check(int tar){
	long long sum=0;
	int cnt=1;
	for(int i=tar-1;i>=0;i--){
		sum+=a[tar]-a[i];
		if(sum<=m){
			cnt++;
		}
		else{
			sum-=(a[tar]-a[i]);
			break;
		}
	}
	mx=max(mx,cnt);
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a,a+n);
	long long l=0,r=n-1,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)==m){
			l+=2;
		}
		else if(check(mid)<m){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<mx;
	return 0;
}
