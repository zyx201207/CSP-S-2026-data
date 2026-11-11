#include<iostream>

using namespace std;

const int N = 2e5 + 10;
int n, m, a[N], ans;

bool check(int x){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if((a[i] & x) == x) cnt++;
	}
	return cnt >= m;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 29; i >= 0; i--){
		if(check(ans | (1 << i))) ans |= (1 << i);
	}
	cout << ans;
	return 0;
}
