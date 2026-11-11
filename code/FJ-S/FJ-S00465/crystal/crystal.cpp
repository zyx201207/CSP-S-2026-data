#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
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

int n, ans = 0, m;
int a[N], f[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(), m = read();
	for (int i = 1;i <= n;i++){
		a[i] = read();
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++){
		f[i] = f[i-1] + a[i];
	}
	int cnt = 2;
	for (int i = 1;i <= n;i++){
		if (n - i < ans)break;
		for (int j = cnt;j <= n;j++){
			int num = (j-i+1)*a[j] - (f[j] - f[i-1]);
			if (m >= num){
				ans = max(ans, j-i+1);
				cnt = j;	
			}
			else break;
		}
	}
	write(ans);
	return 0;
} 
