#include<bits/stdc++.h>
using namespace std;
int n , m , a[200005] , ans , maxx , x1[35] , y1[35] , x2[35];
int an(int x , int y){
	int xx = x;
	int yy = y;
	int i = 0 , j = 0 , s = 0;
	while(xx > 0){
		x1[++ i] = xx % 2;
		xx = xx / 2; 
	}
	while(yy > 0){
		y1[++ j] = yy % 2;
		yy = yy / 2;
	}
	for(int k = min(i , j) ; k >= 1 ; k --){
		x2[k] = 0;
		if(x1[k] == 1 && y1[k] == 1)x2[k] = 1;
	}
		
	int k = 1;
	for(int q = 1 ; q <= min(i , j) ; q ++){
		s += x2[q] * k;
		k*=2;
	}
	return s;
}
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] ;
		maxx = max (maxx , a[i]);
	}
	if(m == 1){
		cout << maxx ;
		return 0;
	}
	else if(m == 2){
		for(int i = 1 ; i < n ; i ++){
			for(int j = i + 1 ; j <= n ; j++){
				ans = max(ans , an(a[i] , a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	else if(m == n - 1){
		for(int i = 1 ; i <= n ; i ++){
			int pp = a[1];
			for(int j = 2 ; j <= n ; j ++){
				if(i != j)
				pp = an(pp , a[j]);
			}
			ans = max(pp , ans);
		}
		int pp = a[2];
		for(int i = 3 ; i <= n ; i ++)
			pp = an(pp , a[i]);
			
		ans = max(pp , ans);
		cout << ans;
		return 0;
	}
	else if(m == n){
		int pp = a[1];
		for(int i = 2 ; i <= n ; i ++)
			pp = an(pp , a[i]);
		cout << pp;
		return 0;
	}
	cout << 3;
	return 0;
}
