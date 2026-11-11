#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 501000;

int n,m,l,r,ans;
long long num,mod,a[N],c[N],sumc[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (int i = 1;i < n;i++) c[i] = a[i] - a[i+1];
	for (int i = 1;i < n;i++) sumc[i] = sumc[i-1] + c[i];
	l = 1,r = 1;
	num = sumc[1];
	while (r < n-1) {	
		while (num <= m && r < n-1) {
			ans = max(ans,r-l+2);
			r++;
			num += sumc[r]-mod;
		}
		while (num > m) {
			mod += c[l];
			num -= (r-l+1)*c[l];
			l++;
		}
	}
	ans = max(ans,r-l+2);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
