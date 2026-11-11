#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
long long m;
bool check(long long mid){
	long long h=0;
	for(int i=1;i<=n;i++){
		if(a[i]<mid){
			h+=(mid-a[i]);
		}
	}
	if(h>m)return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=0,r=1e18,ans=-1;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=n){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
