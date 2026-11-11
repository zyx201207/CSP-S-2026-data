#include<bits/stdc++.h>
using namespace std;

int n, ls = 0, x;
char s[100000010], c;

int main () {
	freopen("string,in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int j = 1; j <= n; j++){
		scanf("%d%c", &x, &c);
		ls += x;
		for(int i = ls - x; i <= ls; i++){
			s[i] = c;
		}
	}
	int l = ls / 2;
	int sum = 0;
	for(int i = 1; i <= ls; i++){
		if(s[i] != s[n - i + 1])
			sum ++;
	}
	printf("%d", sum);
	return 0;	
}

