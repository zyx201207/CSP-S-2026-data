#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
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
int c, t, n, d;
int x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(), t = read(); 
	while (t--){
		n = read(), d = read();
		for (int i = 1;i <= n;i++){
			x[i] = read();
		}
		if (n == 1 || n == 2 || n == 3){
			write(0);
			putchar('\n');
		}
		else if (n == 4){
			if (x[3] - x[1] <= d && x[4] - x[2] <= d){
				write(1);
				putchar('\n');
			}
			else{
				write(0);
				putchar('\n');
			}
		}else if (n == 5){
			int cnt = 0, cnt1 = 0, cnt2 = 0;
			if (x[3] - x[1] <= d && x[4] - x[2] <= d)cnt++;
			if (x[3] - x[1] <= d && x[5] - x[3] <= d)cnt1++;
			if (x[2] - x[1] <= d && x[5] - x[2] <= d)cnt1++;
			if (x[4] - x[1] <= d && x[5] - x[4] <= d)cnt1++;
			if (cnt1 >= 2)cnt++;
			if (x[5] - x[3] <= d && x[4] - x[2] <= d)cnt++;
			write(cnt);
			putchar('\n');
		}else{
			int num = d / (x[2] - x[1]);
			if (num <= 1){
				write(0);
				putchar(0);
			}else{
				int num1 = 3, ans = 0;
				for (int i = 1;i <= num;i++){
					ans += n-num1;
					num1++;
				}
				write(ans);
				putchar('\n');
			}
		}
	}
	return 0;
}
