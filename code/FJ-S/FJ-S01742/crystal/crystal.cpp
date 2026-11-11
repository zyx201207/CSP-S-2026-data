#include<bits/stdc++.h>
using namespace std;
const int N = 5e5;
long long n , m;
long long a[N] , ans = 0;
bool ok = true , op = true;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != i){
			op = false;
		}
	}
	long long c = a[2] - a[1];
	for(int i = 3; i <= n; i++){
		if(a[i] -  a[i - 1] != c){
			ok = false; 
		}
	}
	if(op == true){
		long long i = 1 , ans = 0;
		while(m > 0){
			if(m - 2 * i >= 0){
				m = m - (2 * i);
				ans = 2 * i;
				i++;
			}else{
				break;
			}
		}
		cout << ans + 1 << endl;
		return 0;
	}
	if(ok == true){
		long long ans = 0;
		while(m > 0){
			if(m - 2 * c >= 0){
				m = m - (2 * c);
				ans = 2 * c;
				c = c + c;
			}else{
				break;
			}
		}
		cout << ans + 1 << endl;
		return 0;
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1; i <= n; i++){
		int now = 0;
		for(int len = 2; i + len - 1 <= n; len++){			
			int j = i + len - 1;
			now = now + (a[j] - a[j - 1]) * (len - 1);
			if(now <= m) ans = max(ans , j - i + 1);
		}
	}
	cout << ans << endl;
	return 0;
}
