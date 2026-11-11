#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 * 5 + 10;
long long m , a[N] , b[N] , l , r , v , z , t , s;
long long ans = -1 , c[N] , w;
int n;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 2 ; i <= n ; i++ ){
		b[i] = fabs(a[i] - a[i - 1]);
		c[i] = b[i] + c[i - 1];
	}
	b[1] = 0;
	l = 1;
	r = 2;
	v = r - l + 1;
	s = b[r];
	while(r <= n){
		if(s > m){
			l++;
			v--;
			s -= c[r] - z;
			z += b[l];
		}else{
			ans = max(v , ans);
			r++;
			v++;
			s += (v - 1) * b[r];
		}
		w++;
	}
	cout << ans;
	return 0;
} 
