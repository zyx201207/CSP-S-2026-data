#include <iostream> 
#define int long long
inline int read(){
	int xxxx = 0, ffff = 1;
	char cchh = getchar();
	while(cchh < 48 || cchh > 57) ffff = (cchh == 45 ? -1 : ffff), cchh = getchar();
	while(cchh >= 48 && cchh <= 57) xxxx = (xxxx << 3) + (xxxx << 1) + (cchh ^ 48), cchh = getchar();
	return xxxx * ffff;
} 
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n1, n2;
	std :: string s1, s2;
	n1 = read(), std :: cin >> s1, n2 = read(), std :: cin >> s2;
	if(n1 != n2) puts("0000");
	else{
		putchar('1');
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			putchar('1');
			if((s1[2] <= 'C') == (s2[2] <= 'C')){
				putchar('1');
				if((abs(s1[2] - s2[2]) == 1 && s1[2] <= 'C') || (abs(s1[2] - s2[2]) == 2 && s1[2] > 'C')) putchar('1');
				else putchar('0');
			}
			else puts("00");
		}
		else puts("000");
	}
	return 0;	
}
