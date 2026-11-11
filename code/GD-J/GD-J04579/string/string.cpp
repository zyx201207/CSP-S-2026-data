#include<bits/stdc++.h>
using namespace std;
long long n , a1[200005] , ans , l , r , ll , rr , aa , bb , e;
char a2[200005] , a;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a1[i] >> a2[i];
	
	l = 1 ; r = n;
	while(l < r){
		if(l == 1 && r == n){
			aa = a1[l];
			bb = a1[r];
		}
		else{
			if(e != 1){
				aa = ll;
				bb = rr;
			}
			else e = 0;
		}
		if(ll != 0){
			ans += ll;
			while(bb < ll && l < r){
				bb += a1[r];
				if(a == a2[r]){
					if(bb += a1[r] <= ll)
						ans -= a1[r];
					else{
					ans = ans - (ll - (bb - a1[r]));
					}
				}
				r --;
			}
			bb -= ll;
			ll = 0; aa = 0;
		}
		if(rr != 0){
			ans += rr;
			while(aa < rr && l < r){
				aa += a1[l];
				if(a == a2[l]){
					if(aa += a1[l] <= rr)
						ans -= a1[l];
					else ans = ans - (rr - (aa - a1[l]));
				}
				l ++;
			}
			aa -= rr;
			rr = 0; bb = 0;
		}
		
		if(aa > bb && l < r){
			ll = aa - bb;
			if(a2[l] != a2[r])
				ans += bb;
			a = a2[l];
			r --;
		}
		else if(aa < bb && l < r){
			rr = bb - aa;
			if(a2[l] != a2[r])
				ans += aa;
			a = a2[r];
			l ++;
		}
		else{
			if(a2[l] != a2[r])
				ans += aa;
			l ++;
			r --;
			aa = a1[l];
			bb = a1[r];
			e = 1;
		}
	}
	cout << ans;
	return 0;
}
