#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> check(const long long a[],long long mid,long long n,long long m){
	long long cnt=0;
	for(int i=n-1;i>=0;i--){
		if(a[i]>mid){
			continue;
		}else{
			m-=(long long)(mid-a[i]);
			if(m>=0){
				cnt++;
			}else{
				return {cnt,0};
			}
		}
	}
	return {cnt,1};
}
int main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout) ;
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=0;
	long long l=a[0],r=a[n-1];
	while(l<=r){
		long long mid=(l+r)/2;
		pair<long long ,long long> p=check(a,mid,n,m);
		ans=max(ans,p.first);
		if(p.second==0){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
