#include <bits/stdc++.h>
using namespace std;

int n , m , t , p , l;
int a[1010100] , jojo[1010100];

int main(){
	freopen ("crystal.in" , "r" , stdin);
	freopen ("crystal.out" , "w" , stdout);
	cin >> n >> m;
	p = m;
	jojo[0] = 0;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	for (int i = 1 ; i <= n ; i++){
		t = 0;
		for (int j = 1 ; j <= n ; j++){
			if (a[j] >= a[i]) continue;
			else if (p >= a[i] - a[j]){
				t++;
				p -= a[i] - a[j];
			} 
		}
		p = m;
		jojo[i] = max(t + 1, jojo[i - 1]);
	}
	cout << jojo[n];
	return 0;
}
