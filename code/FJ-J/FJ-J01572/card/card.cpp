#include <bits/stdc++.h>
using namespace std ;

struct zt{
	int s ;
	bool ok ;
};

struct aa{
	int sa ;
	int bk ;
}ans[300050];

int main(){
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
	int n , m , a[300050] ;
	cin >> n >> m ;
	for(int i = 1 ; i <= m ; i++){
		cin >> a[i] ;
		ans[a[i]].bk = 1 ;
	}
	for(int i = 1 ; i <= n ; i++){
		zt zz[300050] = {0};
		int js[300050] = {0};
		for(int j = i ; j <= n ; j++){
			zz[j].s = a[j] ;
			if(js[a[j]] != 0){
				int xxx = 0 ;
				for(int k = 1 ; k <= j ; k++){
					if(zz[k].s == zz[j].s && zz[j].ok != 0){
						xxx = k ;
					}
				}
				for(int k = xxx ; k <= j ; k++){
					zz[k].ok = 0 ;
				}
			}else{
				js[a[j]]++ ;
			}
			zz[j].ok = 1 ;
		}
		for(int j = 1 ; j <= m ; j++){
			if(zz[j].ok == 1){
				ans[zz[j].s].sa++ ;
			}
		}
	}
	for(int i = 1 ; i <= m; i++){
		cout << ans[a[i]].sa <<" ";
	}
	cout << endl ;
	return 0 ;
}
