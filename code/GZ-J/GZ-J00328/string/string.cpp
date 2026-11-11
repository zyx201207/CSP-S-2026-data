
#include <bits/stdc++.h>
using namespace std;
int n = 200005; 
long long n, 
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	
	cin >> n; 
	
	char n; 
	
	long long m = 1, b = n, ans = 0; 
	while((m > 0) || ()) {
		if(c[a] != c[b]){
			if(x[a] >= x[b]){
				x[a] -= x[b]; 
				ans += x[b]; 
				m -= x[b]; 
				b -= x[b]; 
			}
		}
	}
	
	cout << ans + m; 
	return 0;
}


