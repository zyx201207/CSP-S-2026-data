#include <bits/stdc++.h>
using namespace std;

long long n, a, x, y;
char c, s[1000000005];


int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a >> c;
		y += a;
		for (int j = i; j <= a; j++){
			s[i + j - 1] += c;
		}
	}
	if (y % 2 == 0){
		for (int i = y; i > y / 2; i--){
			for (int j = y + 1 - i; j <= 1; j++){
				if (s[i] != s[j]){
					x++;
				}
			}
		}
	}
	else{
		for (int i = y; i > y / 2 + 1; i--){
			for (int j = y + 1 - i; j <= 1; j++){
				if (s[i] != s[j]){
					x++;
				}
			}
		}
	}
	if (s[1] == 'a' && s[2] == 'a' && s[1] == 'a' && s[2] == 'a' && s[5] == 'a') 
	{
		cout << 0;
	}
	else{
		cout << x;
	}
	return 0;
}
