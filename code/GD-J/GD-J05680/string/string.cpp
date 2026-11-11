#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
struct cha{
	ll nu;
	char c;
	ll l;
	ll r;//l和r分别为在拼接字符串中该串字符的位置 
}a[N];
vector<pair<ll, char>> lef;
vector<pair<ll, char>> rig;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	ll len = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i].nu >> a[i].c;
		len += a[i].nu;
	}
	ll le = 1, ri = 1;
	for (int i = 1; i <= n; i++){
		a[i].l = le;
		a[i].r = ri+a[i].nu;
		le += a[i].nu;
		ri += a[i].nu;
	}
	ll mi = len/2;
	if (len%2==1)mi++;
	ll fi = 0, se = -1;
	ll na = 0;
	for (int i = 1; i <= n; i++){
		if (a[i].l>mi){
			rig.push_back({a[i].nu, a[i].c});
			se++;
		}
		else if (a[i].r>mi){
			lef.push_back({mi-a[i].l, a[i].c});
			rig.push_back({a[i].r-mi+1, a[i].c});
			se++;
			na++;
		}
		else {
			lef.push_back({a[i].nu, a[i].c});
			na++;
		}
	}
	ll ans = mi;
//	cout << mi << endl;
	while (fi<=na&&se>=0){
		if (lef[fi].first == rig[se].first){
			if (lef[fi].second == rig[se].second){
				ans -= lef[fi].first;
//				cout << "我是测试代码\n";
			}
			fi++, se--;
		}
		else{
			if (lef[fi].first<rig[se].first){
				if (lef[fi].second == rig[se].second){
					ans-=lef[fi].first;
//					cout << "我是测试代码\n";
				}
				rig[se].first -= lef[fi++].first;
			}
			else{
				if (lef[fi].second == rig[se].second){
					ans-=rig[se].first;
//					cout << "我是测试代码\n";
				}
				lef[fi].first -= rig[se--].first;
			}
		}
	}
//	if (fi==se && lef[fi].second == rig[se].second)ans -= lef[fi].first;
	if (len%2==1)ans--;
	cout << ans;
	return 0;
}
//绷不住了，调半天最后是因为不开long long见祖宗 
//大家千万要记得开longlong，不开会寄。 
