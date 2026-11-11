#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10;
const int M = 2e5 * 500 + 10;
int n;
ll l;
struct Node{
	int x;
	char c;
} a[N];
char s[M], t[M];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d %c", &a[i].x, &a[i].c);
		
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i].x; j++)
			s[++l] = a[i].c;
	}
//	printf("%s\n", s + 1);
	
	ll ans = 0;
	for(int i = 1, j = l; i <= j; i++, j--){
		if(s[i] != s[j]) ans++;
	}
	printf("%lld\n", ans);
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

*/
