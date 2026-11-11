#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;
ll t,num,n,d,ans;
ll a[N],box[N];
ll find(int i,int k,int j){
	if( a[j] - a[i] <= d )  return false;
	if( a[k]-a[i] <= d && a[j]-a[k] <= d ){
		return true;
	}
	return false;
}
ll check(ll a[]){
	ll k=a[2]-a[1]; 
	for(int i=3;i<=n;i++){
		if( a[i] - a[i-1] != k ){
			return false;
		}
	}
	return k;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> t >> num;
	while( num-- ){
		ans = 0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		if( check(a) ){
			ll k = check(a);
	//		cout << k << endl;
			if( d < 2*k ){
				cout << 0 << endl;
			}
			else{
				ll f = d / k -1;
				ll x = d + d - k;
//				cout << f << endl;
//				cout << x << endl;
				x = x / k;
				
				ans = n-x;
				if( ans < 0 )  cout << 0 << endl;
				else cout << ans << endl;
			}
			
			continue;
		} 
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				ll x = 0;
				for(int k=i+1;k<j;k++){
					if(find(i,k,j)){
						x ++;
						cout << i << "" << j << endl;
					}
				}
				if( x == 2 )  ans ++;
			}
		}
		cout << ans << endl;
	}

	return 0;
} 

