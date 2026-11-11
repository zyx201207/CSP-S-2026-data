#include <bits/stdc++.h>
using namespace std;

template <typename T> bool ckmax(T &a,T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}
template <typename T> bool ckmin(T &a,T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

int n,ret=0,j=0;
long long m,pri;
vector<long long> a;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	a.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
	j = 0;
	pri = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			pri += (a[i] - a[i-1]) * (i - j);
		}
		while (pri > m) {
			pri -= a[i] - a[j];
			j++;
		}
		ckmax(ret,i-j+1);
	}
	printf("%d\n",ret);
	
}
