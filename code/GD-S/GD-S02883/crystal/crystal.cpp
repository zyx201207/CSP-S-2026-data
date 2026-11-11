#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500055],s[500055],w[500055],c[500055];
bool check(int x){
	long long k=x-1;
	for(int i=1;i<=n-1;i++) c[i]=c[i-1]+w[i];
	for(int i=k;i<=n-1;i++){
		long long p=c[i]-c[i-k];
		p=p-k*w[i+1];
		if(p <= m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		s[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++){
		w[n-i]=w[n-i+1]+s[n-i];
	}
	long long l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)==true){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
