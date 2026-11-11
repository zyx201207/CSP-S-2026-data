#include<bits/stdc++.h>
using namespace std; 
long long n,k,a[501010],l=1,r,m,b[501010],t;
int c(int x){
	for(int i=x;i<=n;i++){
		if(b[i]-b[i-x+1]<=k) {
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	r=n+1;
	while(l<r){
		m=(r-l)/2+l;
		if(c(m)) l=m+1;
		else r=m;
	}
	cout<<l-1;
	return 0;
} 
