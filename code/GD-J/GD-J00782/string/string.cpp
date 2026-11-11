#include <bits/stdc++.h>
using namespace std;
#define N 200050
long long i, j, k, n, m, a[N], l, ans, x, t, b[N], y;
char c[N], d[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld", &n);
	for(i=1; i<=n; i++){
		scanf("%lld %c", &a[i], &c[i]);
		l+=a[i];
	}
	for(i=1; i<=n; i++){
		b[i]=a[n-i+1];
		d[i]=c[n-i+1];
	}
	for(i=1; t<(l+1)/2; i++){
		if(x>0) {
			b[i]-=x;
			t+=x;
			if(d[i]==c[i-1]) x=0;
			else ans+=x, x=0;
		}
		if(y>0) {
			a[i]-=y;
			t+=y;
			if(d[i]==c[i-1]) y=0;
			else ans+=y, y=0;
		}
		if(d[i]==c[i]){
			t+=min(a[i], b[i]);
			if(a[i]>=b[i]) x=a[i]-b[i];
			else y=b[i]-a[i];
		}
		else if(d[i]!=c[i]){
			t+=min(a[i], b[i]);
			ans+=min(a[i], b[i]);
			if(a[i]>=b[i]) x=a[i]-b[i];
			else y=b[i]-a[i];
		}
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
