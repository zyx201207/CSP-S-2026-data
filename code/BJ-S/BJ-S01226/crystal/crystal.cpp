#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while (!isdigit(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x){
	if (x < 0){
		putchar('-');
		write(-x);
		return ;
	}
	if (x < 10){
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}
int n,m;
int a[500050],s[500050];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(),m = read();
	for (int i = 1;i <= n;i++) a[i] = read();
	sort(a + 1,a + n + 1);
	s[1] = a[1];
	for (int i = 2;i <= n;i++) s[i] = s[i - 1] + a[i];
	int maxx = 0,j = 0;
	for (int i = 1;i <= n;i++){
		while (j <= i && (i - j + 1) * a[i] - s[i] + s[j - 1] > m) j++;
		maxx = max(maxx,i - j + 1);
	}
	write(maxx),putchar('\n');
	return 0;
}