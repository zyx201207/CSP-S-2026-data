#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r;
bool check(long long x){
	long long  cnt=0;
	for(long long i=1;i<x;i++){
		cnt+=a[x]-a[i];
	}
	if(cnt<=m)return true;
	for(int i=2;i<=n-x;i++){
		cnt-=a[i+x-1]-a[i-1];
		cnt+=(a[i+x]-a[i+x-1])*(x-1);
		if(cnt<=m)return true;
	}return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=0,r=n;
	while(l<r){
		long long mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	cout<<(check(l)?l:l-1);
	return 0;
} 
