// 48 pts
#include<bits/stdc++.h>
using namespace std;
string str;
int n, ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int p;
		char x;
		cin >> p >> x;
		str.append(p, x);
	}
	int l = 0, r = str.size() - 1;
	while(l < r){
		ans += (str[l] != str[r]);
		l++;
		r--;
	}
	cout << ans;
	return 0;
}
