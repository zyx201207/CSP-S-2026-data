#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
ll n, m, a[N], s1;
ll ind[N], ids, mxn;
bool bin[N][40];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m), ids=n;
	for(int i=1; i<=n; i++) {
		scanf("%lld", &a[i]), ind[i]=i;
		ll aa=a[i], num=0;
		while(aa) bin[i][++num]=aa&1, aa>>=1;
		mxn=max(mxn, num);
	}
	for(int i=mxn; i>=1; i--, s1=0) {
		for(int j=1; j<=ids; j++)
			s1+=bin[ind[j]][i];
		if(s1<m) continue;
		for(int j=1; j<=ids; j++)
			if(!bin[ind[j]][i])
				swap(ind[j], ind[ids]), j--, ids--;
		if(s1==m) break;
	}
	ll res1=a[ind[1]];
	for(int i=2; i<=ids; i++)
		res1&=a[ind[i]];
	printf("%lld", res1);
	return 0;
}
