#include <bits/stdc++.h>
using namespace std;
const int N = 2*1e9+10;
int n,z = 0,ans = 0;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		int b;
		char c;
		cin >> b >> c;
		for (int j = 1;j <= b;j++){
			a[++z] = c;
		}
	}
	for (int i = 1;i <= z/2;i++){
		if (a[i] != a[z-i]){
			a[z-i] = a[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
