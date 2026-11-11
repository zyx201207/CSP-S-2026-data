#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,l,r;
long long m,a[N],s[N];
bool check(int len){
	for(int i = 1;i <= n - len + 1;i ++){
		int ll = i,rr = i + len - 1;
		long long sum = 1LL * a[rr] * len - (s[rr] - s[ll - 1]);
		if(sum <= m) return true;
	}
	return false;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i ++) s[i] = s[i - 1] + a[i];
	l = 1,r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
} 
