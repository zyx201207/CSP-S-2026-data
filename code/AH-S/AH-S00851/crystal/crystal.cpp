#include <bits/stdc++.h>
using namespace std ;
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n ;
	long long m , a[500086] ;
	int ss = 1 ;
	int ans = -1 ;
	cin >> n >> m ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i] ;
	}
	sort(a+1,a+n+1);
	for( int i = 3 ; i <= n ; i++ ){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				 ss=0 ;
				 break ;
			}
	}
	if(ss){
		long long tt=0 , t = a[2]-a[1] ;
		long long mm = m ;
		while(mm>=0&&ans<n){
			tt+=t ;
			mm-=tt ;
			if(mm>=0) ans++ ;
		}
		cout << ans ;
		return 0 ;
	}
	for( int i = n ; i >= 1 ; i-- ){
		int t = 0 , mm = m , cnt = i-1 ;
		while(mm>=0&&cnt>=1){
			t+=(a[cnt+1]-a[cnt]);
			mm-=t ;
			if(mm>=0) cnt-- ;
		}
		ans=max((i-cnt),ans);
		if(ans==i) break ;
	}
	cout << ans ;
	return 0 ;
}
