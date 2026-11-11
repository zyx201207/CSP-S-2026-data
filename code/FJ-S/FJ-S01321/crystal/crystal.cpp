#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 5e5 + 5;

ll n,m;
ll a[N],q[N];

void solve1(){
	ll ans = 0;
	for(int i = n; i >= 1; i--){
		ll f = m,cnt = 0;
		for(int j = i; j >= 1;j--){
			if(f < a[i] - a[j]) break;
			f -= (a[i] - a[j]),cnt++;
		}
		ans = max(ans,cnt);	
	}
	cout << ans << "\n";
	return;
}

void solve2(){
	ll ans = 0,f = m,pos = n,cnt = 0;
	for(;pos >= 1;pos--){
		if(f < a[n] - a[pos]) break;
		f -= (a[n] - a[pos]),cnt++;
	}
	ans = cnt;
	for(int i = n - 1;pos >= 1;i--){
		cnt--;
		f += cnt * (a[i + 1] - a[i]);
		while(pos >= 1){
			if(f < a[i] - a[pos]) break;
			f -= (a[i] - a[pos]);
			cnt++,pos--;
		}
		ans = max(ans,cnt);
	}
	cout << ans << "\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	if(n <= 5000) solve1();
	else solve2();
	return 0;
}
// warning:"==",全局变量,freopen,check_code
/*T1:贪心？从n->1跑，将最近的分配？ 
n^2 优化？
双指针？一个指向当前，减小时回退数值，指向末尾的指针左移，每次取max 
5 8 
-3 -1 2 2 7
15:09 39min T1bingo!
*/
