#include <iostream>
#define int long long
inline int read(){
	int xxxx = 0, ffff = 1;
	char cchh = getchar();
	while(cchh < 48 || cchh > 57) ffff = (cchh == 45 ? -1 : ffff), cchh = getchar();
	while(cchh >= 48 && cchh <= 57) xxxx = (xxxx << 1) + (xxxx << 3) + (cchh ^ 48), cchh = getchar();
	return xxxx * ffff;
}
signed main(){
//	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	return 0;
}

