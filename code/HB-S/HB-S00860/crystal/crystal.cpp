#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1145141],ans=0,b[1145141];
bool check(long long x,long long i){
	long long sum=b[x-1]-b[i-1];
	if((x-i)*a[x]-sum<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//cout<<abs(-114);
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long l,r,mid;
	//cout<<check(1,1)<<endl;
	for(long long i=2;i<=n;i++){
		if(abs(a[i]-a[i-1])>m) continue;
		//long long sum=1,mm=m;
		l=1;
		r=i;
		while(l<=r){
			mid=(r-l)/2+l;
			if(check(i,mid)){
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		//cout<<l<<" "<<r<<endl;
		ans=max(ans,i-r);
		/*
		for(long long j=i-1;j>=1;j--){
			if(mm>=a[j]){
				mm-=(a[i]-a[j]);
				sum++;
			}
			else {
				mm-=(a[i]-a[j]);
				break;
			}
		}
		ans=max(ans,sum);
		* */
	}
	cout<<ans;
	return 0;
}
