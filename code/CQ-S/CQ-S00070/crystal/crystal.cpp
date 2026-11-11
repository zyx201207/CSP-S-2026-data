#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define intl long long
#define For(i,a,b) for(intl i=a;i<=b;i++)
#define deo(i,a,b) for(intl i=a;i>=b;i--)
intl read() {
	intl x=0,k=1;char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') k = -1; ch = getchar();}
	while(isdigit(ch)) x = (x<<3)+(x<<1)+(ch^48), ch = getchar();
	return x*k;
}
intl n, m, a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	n = read(), m = read();
	For(i,1,n) a[i] = read();
	sort(a+1,a+n+1);
	intl j = 1, ans = 0, sum = 0;
	For(i,1,n) {
//		cout << i << " " << j << endl;
		while(sum > m) sum -= a[i]-a[j], j++;
		ans = max(ans, i-j+1);
		sum += (a[i+1]-a[i])*(i-j+1);
	}
	printf("%lld\n", ans);
	return 0; 
}


