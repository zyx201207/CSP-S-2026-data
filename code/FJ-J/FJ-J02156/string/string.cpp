#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n , ans = 0;
long long a[N];
char c[N];
string s = "";
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i]; 
		for(int j = 1; j <= a[i]; j++){
			s += c[i];
		}
	}
	long long l = s.size();
	for(int i = 0; i < l / 2; i++){
		if(s[i] != s[l - i - 1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
 

