#include <bits/stdc++.h>
using namespace std;
struct node{
	int a, b;
}a[200005];
int n, m;
int f(int x){
	int ans = 0;
	while(x){
		ans++;
		x /= 2;
	}
	return ans;
}
bool cmp(node x, node y){
	return x.a > y.a;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int maxx = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i].a, a[i].b = f(a[i].a), maxx = max(a[i].a, maxx);
	if(m == 1){
		cout << maxx;
	}
	else if(m == 2){
		maxx = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				maxx = max(a[i].a & a[j].a, maxx);
			}
		}
		cout << maxx;
	}
	else if(m == n){
		int maxx = a[1].a;
		for(int i = 2; i <= n; i++){
			maxx = maxx & a[i].a;
		}
		cout << maxx;
	}
	else{
		sort(a + 1, a + 1 + n, cmp);
		int maxx = a[1].a;
		for(int i = 2; i <= m; i++){
			maxx = maxx & a[i].a;
		}
		cout << maxx;
	}
	return 0;
}
