#include <bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],ans,flag,ans2,maxn;
long long check(int x){
	long long cnt=0,m1=0;
	for(int i=n;i>=1;i--){
		if(a[i]>x)continue;
		if(m1+x-a[i]>m){
			flag=1;
			return cnt;
		}
		else {
			m1+=x-a[i];
			cnt++;
		}
	}
	flag=0;
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=a[1],r=a[n],mid=(l+r)/2;
	long long x=check(mid);
	while(l<r){
		if(ans<x)ans=x;
		long long y=check((mid+1+r)/2),z=check((mid+l)/2);
		if(y>z){
			x=y;
			l=mid+1;
		}
		else{
			x=z;
			r=mid;
		}
		mid=(l+r)/2;
	}
	l=a[1],r=a[n],mid=(l+r)/2;
	while(l<r){
		mid=(l+r)/2;
		long long x=check(mid);
		ans2=max(ans2,x);
		if(!flag)l=mid+1;
		else r=mid;
	}
	cout<<max(ans,ans2);
	return 0;
}
