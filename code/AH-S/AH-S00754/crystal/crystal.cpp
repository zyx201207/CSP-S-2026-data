#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],s[500005]; 
long long mx;
long long work(long long x){
	long long l=1,r=x-1;
	while(l<=r){
		long long mid=l+r>>1;
		long long num=x-mid;//need=(x-mid)*a[x],have=sigma(a[mid],a[x-1]).
		long long need=num*a[x];
		long long hav=s[x-1]-s[mid-1];
		if(need-hav<=m)r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		long long len=i-work(i)+1;
		mx=max(mx,len);
	}
	cout<<mx;
	return 0;
}
