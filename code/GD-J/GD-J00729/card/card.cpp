#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int n, m, a[N], r[N];
ll ans[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		r[a[i]]=max(r[a[i]],i);
	}
	for(int i=1;i<=n;i++) {
		int j=i;
		while(j<=n) {
			ans[a[j]]++;
			j=r[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++) {
		printf("%lld ", ans[i]);
	}
	return 0;
} 
