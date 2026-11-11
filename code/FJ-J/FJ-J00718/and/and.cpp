#include <bits/stdc++.h>
using namespace std;
int n, m;
int maxn = 0, a[200010], b[200010];
string p(int u){
	string q;
	while(u){
		q+= u % 10;
		u /= 10; 
	}
	return q;
}
int f(int x, int y){
	int s = x + y;
	string o = p(s);
	int len = o.size(), ans = 0;
	bool flag = 0;
	for (int i = 0; i <= len-1; i ++){
		if (o[i] - '0' == 2) flag = 1;
		if (flag){
			ans *=10;
			if (o[i] - '0' == 2){
				ans += 1;
			}
		}
	}
	return ans;
}
int v(int z){
	string ans;
	int ansc = 0;
	while(z > 0){
		ans += z % 2;
		z /= 2;
	}
	int len = ans.size()/2;
	for (int i = 0; i <= len-1; i ++){
		swap(ans[i], ans[len-1-i]);
	}
	for (int i = 0; i <= len-1; i ++){
		ansc *= 10;
		ansc += a[i] -'0';
	}
	return ansc;
}
int e(int d){
	int anse=0, vs = 1;
	while(d){
		anse += d%10*vs;
		vs*=2;
		d /=10;
	}
	return anse;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		b[i] = v(a[i]);
	}
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n; j ++){
			if (i == j) continue;
			maxn = max(f(b[i], b[j]), maxn);
		}
	}
	cout << e(maxn);
	return 0;
}
