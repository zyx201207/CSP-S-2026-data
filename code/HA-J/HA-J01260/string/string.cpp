#include <bits/stdc++.h>
using namespace std;
string s1, s2, t;
int n, c1, c2, x;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> t;
		for(int j = 1; j <= x; j++){
			s1 = s1 + t;
		}
	}
	int k = 0;
	for(int i = s1.size(); i >= 0; i--){
		s2[k] = s1[i];
		k++;
	}
	if(s1.size() % 2 == 0){
		for(int i = 0; i <= s1.size() / 2; i++){
			if(s2[i] != s1[i]){
				c1++;	
			}
		}
		for(int i = s1.size() / 2; i <= n; i++){
			if(s2[i] != s1[i]){
				c2++;	
			}
		}
	}else{
		for(int i = 0; i < (s1.size() - 1) / 2; i++){
			if(s2[i] != s1[i]){
				c1++;	
			}
		}
		for(int i = (s1.size() + 1) / 2; i <= s1.size(); i++){
			if(s2[i] != s1[i]){
				c2++;	
			}
		}
	}
	cout << min(c1, c2);
	return 0;
}
