// 遵义市第四中学 杨浩辰 GZ-J00124 
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#define f front
#define w back 
using namespace std;
typedef long long ll;
deque<pair<ll,char>> a;
ll cnt = 2;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		char y;
		cin >> x >> y;
		if (y == a.f().second) {
			ll xx = a.f().first, yy = a.f().second;
			a.pop_front();
			a.push_back({xx+x,yy});
			continue;
		} 
		a.push_back({x,y});
		cnt++;
	}
	ll z = cnt, ans = 0;
	while (!a.empty()) {
		if (a.size()==1) break;
		if (a.f().second == a.w().second) {
			if (a.f().first == a.w().first) a.pop_front(),a.pop_back();
			else if (a.f().first > a.back().first) {
				ll s = a.back().first;
				a.pop_back();
				ll b = a.f().first-s;
				while(b>0) {
					if (a.w().first > b) ans += b,a.w().first-=b, b=0;
					else if (a.w().first == b) ans += b, a.pop_back(); 
					else ans += a.back().first, b-=a.w().first, a.pop_back();
				}
			}
		} else if (a.f().first == a.w().first){
			ans += a.f().first; 
			a.pop_front(), a.pop_back();
		} else if (a.f().first > a.w().first) {
			ans += a.w().first; 
			a.f().first-=a.w().first;
			a.pop_back();
		} else {
			ans += a.f().first; 
			a.w().first-=a.f().first;
			a.pop_front();	
		}
	}
	cout << ans;
	return 0;
}
