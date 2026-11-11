#include <bits/stdc++.h>
using namespace std;
const int M = 5e5+5;
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
struct xl{
	int x, load;
};
struct Edge{
	int u, v, jz, hx;
};
int c, n, m, d, q;
int t[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1;i <= m;i++)t[i] = read();
	
	return 0;
}
