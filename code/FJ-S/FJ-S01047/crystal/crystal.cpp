#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
long long m,a[N],ans,l,r,cst;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	l = 1,r = 0;
	for(int i = 1; i <= n; i++){
		++r;
		if(i == 1) cst = 0;
		else cst += (r - l) * (a[r] - a[r - 1]);
		while(cst > m) cst -= a[r] - a[l++];
		ans = max(ans,r - l + 1);
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
