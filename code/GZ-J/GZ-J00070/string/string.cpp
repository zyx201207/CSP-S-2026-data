//GZ-J00070 张善之 贵阳市云岩区中天中学 
#include <bits/stdc++.h>
using namespace std ;
const int N =2e5+10 ;
#define ll long long
struct node {
	char type ;ll num ;bool f ;
}a[N];
int main () {
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) , cout.tie(0) ;
	int n ; cin >> n ;
	for(int i=1;i<=n;i++) {
		cin >> a[i].num >> a[i].type ;
	}
	ll ans = 0 ;
	for(ll i=1,j=n;i<=n;i++,j--) {
		if(a[i].type!=a[j].type) {
			if(a[i].num==a[j].num&&!a[i].f&&!a[j].f){
				ans+=a[i].num ; 
				a[i].num = 0 ;
				a[j].num = 0 ;
				a[i].f = true ;
				a[j].f = true ;
				continue ;
			}
			else if(a[i].num>a[j].num&&!a[j].f) {
			while(1) {
				if(a[i].num<=0) break ;
				if(a[i].num>a[j].num) {
					ans+=min(a[i].num,a[j].num) ; 
					a[i].num-=a[j].num ;
					a[j].num = 0 ;
					a[i].f = true ;
					a[j].f = true ;
					j-- ;
					continue ;
				}
				else if(a[i].num==a[j].num) {
					ans+=a[i].num ;
					a[i].num = 0 ;
					a[j].num = 0 ;
					a[i].f = true ;
					a[j].f = true ;
					break ;
				}
				else {
					ans+=min(a[i].num,a[j].num) ;
					a[j].num -= a[i].num ;
					a[i].num = 0 ;
					a[i].f = true ;
					a[j].f = true ;
					break ;
				}	
			}
				continue ;
			}
			else if(a[i].num<a[j].num&&!a[i].f) {
			while(1) {
				if(a[i].num<=0) break ;
				if(a[j].num>a[i].num) {
					ans+=min(a[i].num,a[j].num) ; 
					a[j].num-=a[i].num ;
					a[i].num = 0 ;
					a[i].f = true ;
					a[j].f = true ;
					i++ ;
					continue ;
				}
				else if(a[i].num==a[j].num) {
					ans+=a[i].num ;
					a[i].num = 0 ;
					a[j].num = 0 ;
					a[i].f = true ;
					a[j].f = true ;
					break ;
				}
				else {
					ans+=min(a[i].num,a[j].num) ;
					a[i].num -= a[j].num ;
					a[j].num = 0 ;
					a[i].f = true ;
					a[j].f = true ;
					break ;
				}	
			}	
				continue ;
			}
			
		}}
		cout << ans ;
		return 0 ;
	}	
	


