#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdout);
	freopen("string.out","w",stdin);
	int n,count;
	int L = 0;
	count = 0;
	int now = -1;
	int a[n] = {0};
	char c[n];
	for (int i = 0;i < n;i++){
		cin >> a[i] >> c[i];
	}
	for (int i = 1;i <= n;i++){
		L += a[i]; 
	}
	char s[L] = {0};
	for (int i =0;i < n;i++){
		for (int j = now+1;j <= now+1+a[i];j++){
			s[j] = c[i];
		}
	}
	for (int i = 0;i <= L/2;i++){
		if (s[i] != s[L+1-i]){
			count++;
		}
	}
	cout << count;
	return 0;
}
