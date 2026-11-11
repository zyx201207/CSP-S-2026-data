#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("string.in" , "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n, num;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num >> str;
		for (int j = 1; j <= num; j++) a += str;
	}
	
	bool ans = 1;
	ll l = 0, r = a.size() - 1;
	while (l < r){
		if (a[l] != a[r]){
			ans = 0;
			break;
		}
		l++;
		r--;
	}
	
	int cnt = 0;
	if (ans == true){
		cout << 0;
		return 0;
	}
	else{
		while (l <= r){
			if (a[l] != a[r]) cnt++;
			l++;
			r--;
		}
	}
	cout << cnt;
	
	return 0;
}
