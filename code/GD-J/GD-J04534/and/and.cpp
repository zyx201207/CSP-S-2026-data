#include <bits/stdc++.h>
#define _for(i,a,b) for(int i = a,IM = b;i <= IM;i ++)
using namespace std;
const int N = 2e5 + 9;

using ll = long long;
int a[N];
int pre[N],nxt[N];
int n,m; 
int calc(int k) {
	int cnt = 0;
	while(k) k &= k - 1,cnt ++;
	return cnt;
}
void solve2(){
	int ans =  0;
	_for(k,1,(1 << n) - 1) {
		if(calc(k) != m)continue;
		int sum = (1 << 30) - 1;
		_for(i,1,n) if(k >> i - 1 & 1) sum &= a[i];
		ans = max(ans,sum);
	}
	cout << ans << '\n';
}
void solve1() {
	if(m == 1){
		int mx = 0;
		_for(i,1,n) mx = max(mx,a[i]);
		cout << mx << '\n';
	}else if(m == 2){
		int ans = 0;
		for(int l = 1;l <= n;l ++){
			for(int r = l + 1;r <= n;r ++){
				ans = max(ans,a[l] & a[r]);
			}
		}
		cout << ans << '\n';
	}else if(m == n){
		int ans = (1 << 30) - 1;
		for(int i = 1;i <= n;i ++)ans &= a[i];
		cout << ans << '\n'; 
	}
} 
bool check(){
	bool flag = true;
	for(int i = 1;i <= n;i ++) if(a[i] > 4)flag = false;
	return flag; 
}
void solve4(){
	int cnt = 0;
	for(int i = 1;i <= n;i ++)if(a[i] & 3) cnt ++;
	if(cnt >= m){
		cout << 3 << '\n';
		return ;
	}
	cnt = 0; 
	for(int i = 1;i <= n;i ++)if(a[i] & 2) cnt ++;
	if(cnt >= m){
		cout << 2 << '\n';
		return;
	}
	cnt = 0; 
	for(int i = 1;i <= n;i ++)if(a[i] & 1) cnt ++;
	if(cnt >= m) {
		cout << 1 << '\n';
		return ;
	}
	cout << 0 << '\n';
}
void solve3() {
	pre[0] = (1 << 30) - 1,nxt[n + 1] = (1 << 30) - 1;
	for(int i = 1;i <= n;i ++)pre[i] = pre[i - 1] & a[i];
	for(int i = n;i >= 1;i --)nxt[i] = nxt[i + 1] & a[i];
	int ans = 0;
	for(int i = 1;i <= n;i ++)ans = max(ans,pre[i - 1] & nxt[i + 1]);
	cout << ans << '\n'; 
}
bool check2(){
	bool flag = true;
	for(int i= 1;i <= n;i ++){
		bool flag2 = false;
		for(int k = 30;k >= 0;k --) if(a[i] = (1 << k) - 1)flag2 = true;
		flag &= flag2;
	} 
	return flag;
}
void solve5() {
	sort(a + 1,a + 1 + n,greater<int>());
	int ans = (1 << 30) - 1;
	for(int i = 1;i <= m;i ++)ans &= a[i];
	cout << ans << '\n'; 
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	_for(i,1,n) cin >> a[i];
	if(n <= 20) solve2(); 
	else if(n <= 3000) solve1(); 
	else if(m == n - 1)solve3(); 
	else if(check2())solve5();
	else if(check()) solve4();
	return 0;
} 
