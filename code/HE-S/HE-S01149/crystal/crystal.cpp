//喵喵喵让我拿90pts好不好喵喵喵 
#include <bits/stdc++.h>
using namespace std;

int n, q;
int ans[500001];
long long m, p;
long long a[500001];

inline void tp(int w){
	int x = a[2] - a[1];
	for (int i = 3; i <= n; i++)
		if (a[i] - a[i - 1] != x)
			return;
	for (int i = 1; i < n; i++){
		if (w - x * i >= 0){
			ans[1]++;
			w = w - x * i;
		}
		else
			break;
	}
	return;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf ("%lld", &a[i]);
		ans[i] = 1;
	}
	sort (a, a + n + 1);
	
	tp(m);//特判等差 
	if (ans[1] != 1){
		printf ("%d\n", ans[1]);
		return 0;
	} 
	
	for (int i = 1; i <= n; i++){//暴力（m稍微小一点） 
		p = m, q = i;
		while (p){
			if (q - 1 > 0){
				p = p - (a[i] - a[--q]);
				if (p >= 0)
					ans[i]++;
			}
			else
				break;
		}
	}
	sort (ans, ans + n + 1);
	printf ("%d\n", ans[n]);
	return 0;
}












