#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], sum,l, r,x,y, ans = 0;
char c[200005], s1, s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("srting.out", "w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] >> c[i];
		
	}
	l = 1, r = n;
	while(l <= r){
		if(l == r){
			cout << ans;
			return 0;
		}
		if(x == 0){
			x = a[l];
			s1 = c[l];
		}if(y == 0){
			y = a[r];
			s2 = c[r];
		}
		if(s1 != s2){
			if(x > y){
				ans += y;
				x -= y;
				y = 0;
				r--;
			}else if(x < y){
				ans += x;
				y -= x;
				x = 0;
				l++;
			}else{
				ans += x;
				y = 0;
				x = 0;
				l++;
				r--;
			}
		}
		else if(s1 == s2){
			if(x > y){
				x -= y;
				y = 0;
				r--;
			}else if(x < y){
				y -= x;
				x = 0;
				l++;
			}else{
				y = 0;
				x = 0;
				l++;
				r--;
			}
		}
	}

	cout << ans;
	return 0;
}
