#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
int a[N],b[N],ans=1,cha;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		cha=a[i]-a[i-1];
		b[i]=b[i-1]+a[i];
	}
	if(n>5000){
		for(int i=2;i<=n;i++){
			if(1LL*(1+a[i])*i/2<1LL*m*cha){
				ans=i;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
//	for(int i=1; i<=n; i++) {
//		long long ne=m;
//		for(int j=1; j<=i; j++) {
//			ne-=(a[i]-a[j]);
//		}
//		if(ne>=0) {
//			ans=max(ans,i);
//		}
//	}
	int l=0,r=1;
	while(l<n&&r<=n){
		if(b[r]-b[l]+m>=a[r]*(r-l+1)){
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
