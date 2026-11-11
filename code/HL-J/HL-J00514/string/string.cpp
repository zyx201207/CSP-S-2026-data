#include<bits/stdc++.h>
using namespace std;

int n;
char s[200010];

int main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%d", &n);
	int l = 0;
	for (int i = 1; i <= n; i++){
		int x;
		char a[2];
		scanf("%d%s", &x, a + 1);
		for (int j = 1; j <= x; j++)
			s[++l] = a[1];
	}
	int ans = 0;
	for (int i = 1; i <= l / 2; i++)
		if (s[i] != s[l - i + 1])
			ans++;
	printf("%d\n", ans);
	
	return 0;
}
