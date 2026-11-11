#include <bits/stdc++.h>
using namespace std;

int n;
long long a[500002];
long long m;
long long suma[500002];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++) suma[i] = suma[i-1] + a[i];
	
	int Ans = 0;
	for(int i=1;i<=n;i++){
		int L = 0, R = i-1;
		while(L < R) {
			int mid = (L + R + 1) >> 1;
			if(1ll * a[i] * mid - (suma[i-1] - suma[i-1-mid]) <= m) L = mid;
			else R = mid - 1;
		}
		Ans = max(L+1, Ans);
	}
	
	printf("%d",Ans);
	
	return 0;
}

/*

3 1
2 2 3

*/
