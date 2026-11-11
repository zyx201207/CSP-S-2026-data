#include <bits/stdc++.h>
using namespace std;
int n;
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string a;
	for (int i = 1;i <= n;i++){
		int a1;
		string c1;
		cin >> a1 >> c1;
		for (int j = 1;j <= a1;j++){
			a += c1;
		}
	}
	int ans = 0;
	int len = a.length();
	int lenb = len;
	len /= 2;
	cout << a << endl;
	for (int i = 0;i < len;i++){
		if (a[i] != a[lenb - 1 - i]){
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}
