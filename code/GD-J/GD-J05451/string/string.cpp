#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
pair<ll, char> a[200005];
ll sum, sumj, sumi, ans;
char ni, nj;
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	a[0] = {0, '?'};
	int pre = 0;
	for(int i = 1; i <= n; ++i){
		ll t;
		char c;
		cin >> t >> c;
		if(c == a[pre].second){
			a[pre].first += t;
		}else{
			a[++pre] = {t, c};
		}
	}
	sumj = a[pre].first, nj = a[pre].second, sumi = a[1].first, ni = a[1].second;
	for(int i = 1, j = pre; i < j; ){
		if(sumj > sumi){
			if(ni != nj) ans += sumi;
			sumj -= sumi;
			++i;
			sumi = a[i].first, ni = a[i].second;
		}else if(sumj < sumi){
			if(ni != nj) ans += sumj;
			sumi -= sumj;
			--j;
			sumj = a[j].first, nj = a[j].second;
		}else{
			if(ni != nj) ans += sumi;
			++i, --j;
			sumi = a[i].first, ni = a[i].second;
			sumj = a[j].first, nj = a[j].second;
		}
	}
	cout << ans;
}
