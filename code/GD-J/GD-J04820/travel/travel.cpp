#include <bits/stdc++.h>
using namespace std;
int m, n, i, j, k, x, y, d[10];
char a, b;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d%c%d%d%c", &n, &x, &a, &m, &y, &b);
	d[1] = (n==m), d[2] = (d[1]&&x==y);
	if(a <= 'C') i = 1;
	else i = 0;
	if(b <= 'C') j = 1;
	else j = 0;
	d[3] = (d[2]&&!(i^j)), d[4] = (abs(a-b)==1&&d[3]);
	for(i=1; i<=4; i++) printf("%d", d[i]);
	return 0;
} 
