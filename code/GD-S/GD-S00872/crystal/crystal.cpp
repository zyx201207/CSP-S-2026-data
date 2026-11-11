#include <bits/stdc++.h>
using namespace std;
long long i, j, k, n, m, x, y, a[500050], t, p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	x=y=n;
	while(x<=y&&x>=1){
		if(a[y]-a[x]+t<=m){
			t+=a[y]-a[x];
			k++;
			x--;
			if(k>p) p=k;
		}   
		else if(a[y]-a[x]+t>m){
			k--;
			t-=(a[y]-a[y-1])*k;
			y--;
		} 
	}
	printf("%lld\n", p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
