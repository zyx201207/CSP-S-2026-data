#include <bits/stdc++.h> 
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int a[N];
char c[N];
int main(){
 	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	int n; cin >> n;
	string s;
	ll ans = 0;
    for(int i = 1; i <= n; i++){	
    	cin >> a[i] >> c[i];
    	for(int j = 0; j < a[i]; j++) s += c[i];
	}
	for(ll i = 0; i < s.size() / 2; i++){
		 if(s[i] != s[s.size() - 1 - i]) ans++;
	} 
	cout << ans;	
	return 0;
}
