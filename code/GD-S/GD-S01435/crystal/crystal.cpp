#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 5e5 + 10;
int n;
LL a[N], f[N], pos[N], m;

LL check(int l, int r){
	if(l == r) return f[r];
	else return f[r] - (l - 1) * (a[r] - a[l]) - f[l];
}

bool pd(int r, int l){
	if(check(l, r) <= m) return true;
	else return false;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	memset(f, 0, sizeof f);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1); 
	for(int i = 2; i <= n; i++){
		f[i] += f[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int l = i + 1, r = n;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(pd(mid, i)) l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, l - i);
	}
	cout << ans;
	return 0;
}
