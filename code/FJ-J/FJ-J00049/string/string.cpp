#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, ans;
string s;

signed main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		int ina;
		char inc;
		cin >> ina >> inc;
		while(ina--)s += inc;
	}
	s = " " + s;
	//cout << s << "\n";
	
	int i = 0, j = s.length();
	while(i <= j){
		i++, j--;
		if(s[i] != s[j] && i <= j)ans++;
		//cout << i << "-" << s[i] << " and " << j << "-" << s[j] << "\n";
	}
	cout << ans << "\n";
	
	return 0;
} 
