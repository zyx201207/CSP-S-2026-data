#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5; 
//and是单调不升的
//考虑贪心
ll n, m, a[N], cnt = 0;
ll lt[35];
queue<ll> ans;
void init(){
	for(ll i = 0; i <= 30; i ++){
		lt[i] = pow(2LL, i);
	}
}
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	init();
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int l = 30; l >= 0; l --){
		queue<ll> q;
		cnt = 0;
		for(int i = 1; i <= n; i ++){
			if(a[i] == -1) continue;
			if(lt[l] & a[i]) {
				cnt ++;
				q.push(a[i]);
			}
		}
		//cout << cnt << ' ' << ans.size() << ' ' << q.size() << ' ' << lt[l] << endl;
		if(cnt >= m) {
			ans = q;
			for(int i = 1; i <= n; i ++){
				//cout << lt[l] << ' ' << a[i] << ' ' << (lt[l] & a[i]) << endl;
				if((lt[l] & a[i]) == 0) a[i] = -1;
			}
		}
	}
	if(ans.empty()) cout << 0;
	else{
		ll aans = ans.front();
		ans.pop();
		for(int i = 2; i <= m; i ++){
			aans &= ans.front();
			ans.pop();
		}
		cout << aans;
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
