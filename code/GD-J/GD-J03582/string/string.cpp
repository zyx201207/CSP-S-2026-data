#include <bits/stdc++.h>
using namespace std;
#define int long long
char a[200100];int  b[200100];
 main(){
 	freopen("string.in", "r", stdin); 
 	freopen("string.out", "w", stdout);
// 	freopen("string.in", "r", stdin); 
// 	freopen("string.out", "w", stdout);
// 	freopen("string.in", "r", stdin); 
// 	freopen("string.out", "w", stdout);
// 	freopen("string.in", "r", stdin); 
// 	freopen("string.out", "w", stdout);
// 	freopen("string.in", "r", stdin); 
// 	freopen("string.out", "w", stdout);
// 	freopen("string.in", "r", stdin); 
// 	freopen("string.out", "w", stdout);
// 	freopen("string.in", "r", stdin); 
// 	freopen("string.out", "w", stdout);
// 	freopen("string.in", "r", stdin); 
// 	freopen("string.out", "w", stdout);
// 	freopen("string.in", "r", stdin); 
// 	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> b[i] >> a[i];
	}
	int l = 1, r = n;
	int yul = b[l], yur = b[r];
	int ans = 0;
	while(l < r){
		if(a[l] == a[r]){
			if(yul >= yur){
				yul -= yur;
				yur = b[--r];
			}else{
				yur -= yul;
				yul = b[++l];
			}
		}else{
			ans += min(yul, yur);
			if(yul >= yur){
				yul -= yur;
				yur = b[--r];
			}else{
				yur -= yul;
				yul = b[++l];
			}
		}
	}
	cout << ans << endl;
}
