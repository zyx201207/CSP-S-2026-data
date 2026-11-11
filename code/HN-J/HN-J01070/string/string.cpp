#define MAXN 200005
#include <bits/stdc++.h>
using namespace std ;
long long n,ans;
struct node{
	int l , e ;
};
node a[MAXN] ;
int main(){
	ios::sync_with_stdio(false) ;
	cin.tie(0) ; cout.tie(0) ;
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	cin >> n ;
	int l = 1 , r = n  ;
	for(int i = 1 ; i <= n ; i ++ ){
		char c ;
		cin >> a[i].l >> c ;
		a[i].e = c-'a' ;
	}
	while(l < r){
		int mi = min(a[l].l,a[r].l) ;
		if(a[l].e != a[r].e ){
			ans +=mi ;
		}
		a[l].l -= mi ;
		a[r].l -= mi ;
		if(a[l].l == 0) l ++ ;
		if(a[r].l ==0) r -- ;
	}
	cout << ans ;
	return 0;
}
