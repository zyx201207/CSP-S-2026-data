#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int p = n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int cnt = 0;
	for(int p = n; p > 0; p--){
		string s;
		for(int i = n-p+1; i <= n; i++){
			s += a[i];
			cnt++;
			if(cnt >= 1){
				for(int j = 0; j <= cnt-1; j++){
					if(s[j] == s[cnt-1] && s[j] != 0){
						s[j] = 0;
						s[j+1] = 0;
					}
				}
			}
		}
		string c;
		int re = 0;
		for(int i = 0; i <= cnt-1; i++){
			if(s[i] != 0 && s[i] <= m){
				for(int j = 0; j <= n; j++){
					if(s[i] == c[j]){
						re = 1;
					}
				}
				if(re == 0){
					b[s[i]]++;
				}
				
			}
		}
	}
	
	for(int i = 1; i <= m; i++){
		cout << b[i] << " ";
	}
	return 0;
}
