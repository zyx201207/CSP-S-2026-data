#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
char s1[5], s2[5];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;scanf("%d%s%d%s", &c1, s1, &c2, s2);
	if(c1 != c2)return puts("0000"), 0;
	putchar('1');
	if(s1[0] != s2[0] || s1[1] != s2[1])return puts("000"), 0;
	putchar('1'); 
	bool a1 = (s1[2] <= 'C'), a2 = (s2[2] <= 'C');
	if(a1 ^ a2)return puts("00"), 0;
	putchar('1');
	if(abs(s1[2] - s2[2]) == 1)putchar('1');
	else putchar('0'); 
	return 0;
} 
