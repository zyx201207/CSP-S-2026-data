#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;

int n;
LL a[N];
char ch[N];

LL Sum, L, R;

LL Ans;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld %c", &a[i], &ch[i]);
		Sum += a[i];
	}
	
	if (Sum % 2) L = Sum / 2, R = L + 2;
	else L = Sum / 2, R = L + 1; 
	
	LL Lsum = 0, Rsum = Sum, cur_l = a[1], cur_r = a[n];
	for (int posl = 1, posr = n; posl <= posr; ){
		if (Lsum > L) cur_l = L - Lsum + a[posl], Lsum = INT_MIN;
		if (Rsum < R) cur_r = Rsum + a[posr] - R, Rsum = INT_MIN;
		
		if (ch[posl] != ch[posr]) Ans += min(cur_l, cur_r);
		
		if (cur_l <= cur_r) cur_r -= cur_l, cur_l = a[++posl], Lsum += a[posl];
		else cur_l -= cur_r, cur_r = a[--posr], Rsum -= a[posr];
	}
	
	printf("%lld\n", Ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
