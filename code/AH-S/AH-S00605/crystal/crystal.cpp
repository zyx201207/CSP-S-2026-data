#include<bits/stdc++.h>
using namespace std;

int n;

long long m;

long long arr[512345];

long long sum[512345];

bool check(int x){
	long long cst=0x3f3f3f3f3f3f3f3f;
	for(int i=x;i<=n;i++){
		cst=min(cst,arr[i]*x-sum[i]+sum[i-x]);
	}
	return cst<=m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	int l=1,r=n;
	int ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
