//string
#include <stdio.h>
int n;
long long length[214514];
char chrs[214514];
long long Min(long long a, long long b) {return (a < b) ? a : b;}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	int i;
	for(i = 1; i <= n; i += 1) {
		scanf("%lld %s", &length[i], chrs + i);
	}
	int lp = 1, rp = n;
	long long count = 0;
	while(lp < rp) {
		long long mn = Min(length[lp], length[rp]);
		if(chrs[lp] != chrs[rp]) {
			count += mn;
		}
		length[lp] -= mn;
		length[rp] -= mn;
		if(length[lp] == 0) lp += 1;
		if(length[rp] == 0) rp -= 1;
	}
	printf("%lld\n", count);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
