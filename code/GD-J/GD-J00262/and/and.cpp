#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m;
long long a[N], dif[N];
long long ans = -1;
long long cont(){
	long long reval, c = 0;
	bool f = 1;
	for (int i = 1; i <= n; i++){
		cout << dif[i] << " ";
		if (dif[i]){
			c++;
		}
	}
	cout << '\n';
	if (c == m){
		for (int i = 1; i <= n; i++){
			if (f && dif[i]){
				reval = a[i];
				f = 0;
			}
			if (dif[i]){
				reval = (reval & a[i]);
			}
			cout << dif[i] << ' ';
		}
		cout << '\n';
		return reval;		
	}else{
		return -2;
	}
}
void sch(int cnt){
	if (cnt == m){
		ans = max(cont(), ans);
		return;
	}
	for (int i = 1; i <= n; i++){
		dif[i] = 1;
		sch(cnt + 1);
		dif[i] = 0; 
	}
	return;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	for (int i = 1; i <= n; i++){
		cin >> n >> m;
		cin >> a[i];
	}
	sch(0);
	cout << ans;
	return 0;
}
