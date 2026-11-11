#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200001];
char c[200001], s[100000000000001];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	long long t = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i]; j++){
			s[++t] = c[i];
		}
	}
	long long corr = 0;
	for(int i = 1; i <= t / 2; i++){
		if(s[i] != s[t - i + 1]){
			corr++;
		}
	}
	printf("%d\n", corr);
	return 0;
} 
