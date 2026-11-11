#include <bits/stdc++.h>

using namespace std;

string s , c;

int a[2000100] , n , c1;

long long m , m2;

char b[2000100];

int main (){

	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	
	cin >> n;
	
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i] >> b[i];
		m += a[i];
	}
	
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1 ; j <= a[i] ; j++){
			s += b[i];
		}
	}
	
	c = s;
	
	reverse(s.begin() , s.end());
	
	if(m % 2 == 0){
		m2 = m / 2; 
	} else {
		m2 = m / 2 + 1;
	}
	
	if(c == s){
		cout << 0;
		return 0;
	} else {
		for (int i = 0 , j = m - 1 ; i < m2 - 1 , j >= m2 - 1 ; i++ , j--){
			if (c[i] != c[j]){
				c1++;
			}
		}
	}
	
	cout << c1;

	return 0;
}
