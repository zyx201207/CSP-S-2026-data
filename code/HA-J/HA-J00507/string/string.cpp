#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n;
int a[N];
long long len = 1, ans = 0;
long long s[N];
int l = 0;
char c[N];

int main(){
	freopen("string.in","r", stdin);
	freopen("string.out","w", stdout); 
	s[1] = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %c", &a[i], &c[i]);
		len += a[i - 1];
		if(i > 1)
			s[i] = len;
	}
	len += a[n];
	s[n + 1] = len;
	int x = 1, y = n;
	for(; s[x] <= len / 2;){
		if(x == y)
			break; 
		long long ll = s[x + 1] - s[x], lr = s[y + 1] - s[y];
		long long mn = min(ll, lr);
		if(c[x] != c[y])
			ans += mn;
		if(ll < lr){
			x++;
			s[y + 1] -= mn;
		}
		if(ll > lr){
			y--;
			s[x] += mn;
		}
		if(ll == lr){
			x++, y--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
