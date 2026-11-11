#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,ans;
long long m,a[N],c[N],maxx;
bool op;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(a[i],maxx);
	}
	if(m >= maxx * n) {cout << n;return 0;}
	sort(a + 1,a + n + 1);
	for(int i = 2; i <= n; i++) {
		c[i - 1] = a[i] - a[i - 1];
		if(c[i - 1] != c[1]) op = 1;
	}
	int p = 1;
	while(p < n){
		long long res = 0;
		for(int cnt = 1; p + cnt <= n; cnt++){
			if(res + cnt * c[p + cnt - 1] > m) {ans = max(ans,cnt);break;}
			res += cnt * c[p + cnt - 1];
		}
		if(!op) break;
		p++;
	}
	cout << ans;
	return 0;
}