// check long long & freopen EZ

#include <bits/stdc++.h>
using namespace std;

const int N=500009;

int n;
long long m, a[N], s[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i=1; i<=n; i++)	scanf("%lld", &a[i]);
	
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++)	s[i]=s[i-1]+a[i];
	
	int j=1, ans=0;
	for (int i=1; i<=n; i++){
		while (j<i && (i-j+1)*a[i]-(s[i]-s[j-1])>m)	j++;
		ans=max(ans, i-j+1);
	}
	
	printf("%d\n", ans);
	return 0;
}
