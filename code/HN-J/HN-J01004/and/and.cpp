#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1;a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n-1){
		long long x=0;
		for(int i=n-1;i>=1;i--){
			if(i==n-1)x=a[n]&a[n-1];
			else x&=a[n];
		}
		cout<<x;
		return 0;
	}
	for(int i=n-1;i>=1;i--){
		if(a[i]==a[i+1]){
			cout<<a[i];
			return 0;
		}
	}
	return 0;
}
