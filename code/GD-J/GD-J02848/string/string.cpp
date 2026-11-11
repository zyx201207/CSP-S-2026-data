#include<bits/stdc++.h>
using namespace std;
long long n, ai, L, ans;
char ci, S[200000005];
//struct Node {
//	long long Start;
//	long long End;
//	char C;
//} A[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for(long long i = 1; i <= n; i ++) {
		scanf("%lld %c", &ai, &ci);
		for(int j = L + 1; j <= L + ai; j ++) {
			S[j] = ci;
		}
		L += ai;
	}
	for(int i = 1; i <= L / 2; i ++) {
			//cout << S[i];
		if(S[i] != S[L + 1 - i]) {
			ans ++;
		}
	}
	printf("%lld", ans);
	return 0;
}
