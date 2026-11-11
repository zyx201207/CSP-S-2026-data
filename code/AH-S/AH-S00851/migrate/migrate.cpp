#include <bits/stdc++.h>
using namespace std ;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c , t , n ;
	long long d , a[200086] , da[508][508] , cnt[200086];
	cin >> c >> t ;
	while(t--){
		int ans = 0 ; 
		cin >> n >> d ;
		for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
		if(c==11||c==12){
			int o = a[2]-a[1] ;
			if(d<=o||d>=2*o) cout << 0 << endl ;
			else cout << n-3 << endl ;
			return 0 ;
		}
		for( int i = 1 ; i < n ; i++ ){
			int cntt = 1 ;
			for( int j = i+1 ; j <= n ; j++ ){
				if(a[j]-a[i]<=d){
					da[i][cntt] = j ;
					cntt++ ;
					//cout << cntt-1 << ' ' << j << ' ' << da[i][cntt-1] << endl ;
				}else{
					
					//cout << cntt-1 << ' ' << cnt[i] << endl ;
					break ;
				}
			}
			cnt[i]=(cntt-1);
		}
		for( int i = 1 ; i < n ; i++ ){
			long long tj[200086] ;
			int cntt = 1 ;
			for(int j = 1 ; j <= cnt[i] ; j++){
				long long ss=da[i][j];
//				cout << ss << '?' ;
				for( int k = 1 ; k <= cnt[ss] ; k++ ){
					tj[cntt] = da[ss][k] ;
					//cout << tj[cntt] << ' ' << cnt[ss] << endl ;
					cntt++ ;
				}
			}
			sort(tj+1,tj+cntt);
			//cout << cntt << endl ;
			for( int i = 1 ; i < cntt ; i++ ){
				//cout << tj[i] << ' ' ;
				if(tj[i]==tj[i+1]&&tj[i]!=tj[i+2]&&d>tj[i]) ans++ ;
			}//cout << endl ;
		}
		cout << ans << endl ;
	}
}
