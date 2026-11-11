#include <bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if (ch == '-')w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s*10 + ch -'0';
		ch = getchar();
	}
	return s * w;
}
void write(int a){
	if (a < 0){
		putchar('-');
		a = -a;
	}
	if (a > 9)write(a/10);
	putchar(a%10+'0');
}

signed main(){
	freopen("")
	return 0;
}
