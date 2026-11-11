#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n];
	string s;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> s[i];
	}
	if(n == 2 && s[0] != s[1]){
		int j = max(a[0],a[1]);
		int k = min(a[0],a[1]);
		int jk = j + k;
		int kj = j - k;
		cout << jk / 2 - kj + 1;
	}
	else{
		cout << 0;
	}
	return 0;
} 
