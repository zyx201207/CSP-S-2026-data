#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1 , K = 31;
long long n , m , a[N] , k[K][N] , s , t , w , h;
int q[N] , qp;
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		t = a[i];
		w = 0;
		while(t / 2){
			w++;
			if(t % 2) k[w][i]++;
			t /= 2;
		}
	}
	for(int i = K - 1;i >= 0;i--){
		for(int j = 0;j < n;j++){
			h = 0;
			if(k[i][j] && qp ^ q[j]){
				h++;
				q[j] = 1;
			}
			if(h == m){
				s += pow(2 , i);
				qp = 1;
			}
			
		}
	}
	cout << s;
	return 0;
}
