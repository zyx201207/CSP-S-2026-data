# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500005], b[500005], s[500005], w, z = -1;
int Sum(int n){
	int v = 1, x = -1;
	for(int i = 2; i <= n; i++){
		x = max(v, x);
		if(a[i]==a[i-1]){
			v++;	
		}
		else{
			v = 1;
		}
	}
	return x;
}
int main(void){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
 	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		b[i] = a[i];
	}
	if(m == 0){
		cout << Sum(n);
		return 0;
	}
	for(int i = 1; i <= n; i++){
		int t = m;
		w = a[i];
		for(int j = 1; j <= i; j++){
			if(t <= 0) break;
			if(i == j) continue;
			if(t - (w - a[i]) >= 0){
				t -= w - a[j];
				a[j] = w;
			}
		}
		sort(a+1, a+n+1);
		z = max(Sum(n), z);
		for(int j = 1; j <= n; j++){
			a[j] = b[j];
		}
	}
	cout << z;
	
	return 0;
}
