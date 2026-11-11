#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[500001],b[500001],ma = -1,p;
bool t = 1, o = 1;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		if (a[i] != i)
			t = 0;
		if (i == 2)
			p = a[i] - a[i - 1];
		if (a[i] - a[i - 1] != p)
			o = 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
		b[i] = a[i] - a[i - 1];
	b[1] = 0;
	for (int i = 2; i <= n; i++)
		b[i] += b[i - 1];
	if (t || o){
		for (int i = 1; i <= n; i++)
			if (b[i] <= m)
				ma = i * 1LL;
		printf("%lld", ma); 
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if (b[i] - b[j] <= m && i - j >= ma)
				ma = i - j + 1LL;
	printf("%lld", ma);
}
