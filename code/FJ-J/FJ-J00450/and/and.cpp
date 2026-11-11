#include<bits/stdc++.h>
using namespace std ;
long long a[999999],maxn=-1e18;
int main(){
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	int n,m,c=1e9 ;
	cin >>n>>m ;
	for(int i=1;i<=n;i++){
		cin >>a[i] ;
	}
	sort(a+1,a+n+1) ;
	maxn=a[n] ;
	if(m==1){
		cout << maxn ;
		return 0 ;
	}
	long long sum=-1e18 ;
	if(m==2){
		for(int i=n;i>=2;i--){
			sum=max(sum,a[i]&a[i-1]) ;
		}
		cout << sum ;
		return 0 ;
	}
	for(int i=n;i>=m;i--){
		long long x=a[i],t=i ;
		for(int j=1;j<=m-1;j++){
			t-- ;
			x=(x&a[t]) ;
		}
		sum=max(sum,x) ;
	}
	cout << sum ;
	return 0 ;
}

