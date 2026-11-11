#include <bits/stdc++.h>;
using namespace;

int n = 0;
int cnt = 0;
char S = " ";
int len = 0;
int main(){
	freopen("string.im", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i <= n; i++){
		int geshu = 0;
		char zimu = " ";
		cin >> geshu >> zimu;
		S = S + geshu * zimu;
		len = len + geshu;
	}
	for (int i = 0; i <= len; i++){
		if(S[i] != s[-i]){
			cnt++;
		}
	}
	cout << cnt;
	
}
