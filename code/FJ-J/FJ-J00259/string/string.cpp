#include <iostream>
typedef long long ll;
using namespace std;
pair<ll, char> a[200010];
int head = 1, tail = 1;
int n;
ll ans;
ll mn(ll a, ll b){
	return (a < b)? a : b;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}
	tail = n + 1;
	while(tail - head > 1){
		if(a[head].second == a[tail - 1].second){
			int tmp = mn(a[head].first, a[tail - 1].first);
			a[head].first -= tmp, a[tail - 1].first -= tmp;
			if(a[head].first == 0) head++;
			if(a[tail - 1].first == 0)tail--;
		}else{
			int tmp = mn(a[head].first, a[tail - 1].first);
			a[head].first -= tmp, a[tail - 1].first -= tmp;
			ans += tmp;
			if(a[head].first == 0) head++;
			if(a[tail - 1].first == 0)tail--;
		}
	}
	cout << ans;
	return 0;
}
