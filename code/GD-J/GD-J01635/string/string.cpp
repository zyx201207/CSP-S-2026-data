#include<bits/stdc++.h>
using namespace std;
int n;  
char s[200020];
bool b[200020];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	memset(b, 0, sizeof(b));
	scanf("%d", &n);
	int len = 0;
	for(int i = 1; i <= n; i++){
		int a;
		char c;
		scanf("%d %c", &a, &c);
		for(int j = 1; j <= a; j++)
			s[++len] = c;
	}
	long long ans = 0;
	for(int i = 1; i <= len; i++)
		if(!b[i] && !b[len + 1 - i] && s[i] != s[len + 1 - i]){
			ans++; 
			b[i] = 1; 
			b[len + 1 - i] = 1;
		}
	printf("%lld\n", ans);
}
