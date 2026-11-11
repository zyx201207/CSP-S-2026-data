#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1e6 + 6;

int C, T, n, q[N];
ll D, a[N], b[N], c[N];

void fun2(){
	ll res = 0;
	int tt = 0;
	for(int i = 1; i <= n; i++) b[i] = c[i] = 0;
	for(int i = 1; i <= n - 3; i++){
		if(a[i + 1] - a[i] <= D && a[i + 2] - a[i] <= D && a[i + 3] - a[i] > D){
			if(a[i + 3] - a[i + 1] <= D){
				b[i] = 1;
				b[i + 4] = -1;
				res++;
				q[++tt] = i;
			}
		}
	}
	for(int i = 1; i <= n; i++) c[i] = c[i - 1] + b[i];
	for(int x = 1; x <= tt; x++){
		int i = q[x];
		if((c[i] + c[i + 1] + c[i + 2] + c[i + 3]) > 4) continue;
		ll cnt = 0, cnt2 = 0;
		for(int j = i - 1; j >= q[x - 1] + 1; j--){
			if(a[j + 1] - a[j] <= D) cnt++;
			else break;
		}
		for(int j = i + 1; j <= max(q[x + 1], n); j++){
			if(a[j] - a[j - 1] <= D) cnt2++;
			else break;
		}
		res += 1ll * cnt * cnt2;
	}
	printf("%lld\n", res);
	return;
}

void work(){
	scanf("%d%lld", &n, &D);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	fun2();
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while(T--) work();
	return 0;
}
