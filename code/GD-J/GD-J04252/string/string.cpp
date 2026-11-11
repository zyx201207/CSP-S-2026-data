#include <cstdio>
#include <algorithm>
#define ll long long
#define N 200005
using namespace std;

int n, i, j;
char c[N][2], b[N];
ll m, a[N], ans, l, r, f;
int main(){
	//rp++
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%lld%s", a+i, c[i]);
		b[i] = c[i][0];
		a[i] += a[i-1];	//ai:第i个的结束位置 
	}
	l = 0, r = a[n]+1;
	for(i=1, j=n; i<j; ){
		f = min(min(a[i]-l, r-a[j-1]-1), a[n]/2-l);
		if(b[i] != b[j]){
			ans += f;
		}
		l += f, r -= f;
		if(l >= a[i])	i++;
		if(r <= a[j-1]+1)	j--;
	}
	printf("%lld", ans);
	return 0;
}	//xw
