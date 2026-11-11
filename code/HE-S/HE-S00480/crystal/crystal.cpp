#include<bits/stdc++.h>
using namespace std;
long long a[10001000];
long long f[10001000];
long long n,m;
bool ax(){
	for(long long i=2;i<=n;i++){
		if(a[i]-a[i-1]!=1) return 0;
	}
	return 1;
}
int bx(){
	int gc=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		if(a[i]-a[i-1]!=gc) return 0;
	}
	return gc;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(ax()){
		for(long long i=n;i>=1;i--){
			if((1+i)*i/2<=m) {
				cout<<i+1;
				return 0;
			}
		}
		
	}
	if(bx()){
		for(long long i=n;i>=1;i--){
			if(bx()*(1+i)*i/2<=m) {
				cout<<i+1;
				return 0;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	for(long long i=n;i>=1;i--){
		if(a[i]*i-f[i]<=m) {
			cout<<i;
			return 0;
		}
	}
	return 0;
}
