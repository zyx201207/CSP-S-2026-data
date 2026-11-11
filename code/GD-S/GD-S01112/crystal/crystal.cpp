#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int N = 5e5+5;
i64 a[N], m, st[N][30], s[N];
int n;
i64 query(int l, int r){
	int lg2 = log2(r-l+1);
	return max(st[l][lg2],st[r-(1<<lg2)+1][lg2]);
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	sort(a+1,a+n+1);
	
	for(int i = 1;i <= n;i++) st[i][0] = a[i], s[i] = s[i-1] + a[i];
	
	for(int j = 1;(1<<j)<=n;j++){
		for(int i = 1;i + (1 << j) - 1 <= n;i++){
			st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
	
	int l = 1;
	
	int maxn = 0;
	
	for(int r = 1;r <= n;r++){
		while(__int128(1) * query(l,r) * (r-l+1) - (s[r]-s[l-1]) > m){
			l++;
		}
		maxn = max(maxn, r-l+1);
	}
	cout << maxn;
}
