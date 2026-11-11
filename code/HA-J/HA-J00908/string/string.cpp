#include <bits/stdc++.h>
using namespace std;

int n;
char s[1000000001];

int main () {
	
	freopen ("string.in" , "r" , stdin); 
	freopen ("string.out" , "w" , stdout);
	scanf ("%d", &n);
	long long tot = 0;
	long long a;
	char c;
	for (int i = 1 ; i <= n ; i ++) {
		scanf ("%d" , &a);
		cin >> c;
		for (int j = 1 ; j <= a; j ++) 
			s[++ tot] = c;
	}
//	for (int i = 1 ; i <= tot ; i ++) 
//		printf ("%s" , s[i]);
	bool ok = true;
	for (int i = 1 , j = tot ; i < j ; i ++ , j --) 
		if (s[i] != s[j]) {
			ok = false;
			break;
		}
	if (ok) {
		printf ("0");
		return 0;
	}
	int ans = 0;
	for (int i = 1 , j = tot ; i < j ; i ++ , j --) 
		if (s[i] != s[j]) 
			ans ++;
	printf ("%d", ans);
//	printf ("\nTime : %d", clock());
	return 0;
}
