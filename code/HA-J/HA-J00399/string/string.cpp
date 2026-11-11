#include <bits/stdc++.h>			
using namespace std;
long long n,f = 0 , q=0 ;
double s[100005] , d[100005] , z[1005] , x[1005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int a;
		cin >> a;
		double m;
		cin >> m;
		for(int j = 1 ; j <= a ; j++){
			s[j] = m;
			q++;
		}
	}
	
	if(q%2 == 0){
		for(int i = 1 ; i <= q /2 ; i++){
			x[i] = s[i];
			z[i] = s[q-i+1];
		}
		for(int j = 1 ; j <= q/2 ; j++){
			if(x[j] != z[j]){
				f++;
			}
		}
	}
	else{
		for(int i = 1 ; i <= (q-1)/2 ; i++){
			x[i] = s[i];
			z[i] = s[q-i+1];
		}
		for(int j = 1 ; j <= (q-1)/2 ; j++){
			if(x[j] != z[j]){
				f++;
			}
		}
	}
	cout << f;
	return 0;
}
