#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool check(long long k){
//	cout<<k<<" "<<;
	long long len=upper_bound(a+1,a+1+n,k)-a;
	long long cnt=0,sum=0;
	for(int i=len;i>=1;i--){
		if(a[i]>k){
			continue;
		}
		cnt+=(k-a[i]);
		if(cnt<=m){
			sum++;
		}else{
			break;
		}
	}
	ans=max(ans,sum);
	return cnt>m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=a[1],r=a[n];
	while(l<r){
		long long mid=(l+r)/2;
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
