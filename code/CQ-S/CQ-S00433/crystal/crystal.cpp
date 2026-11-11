#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[1000005],mx,l = 1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,s = 0;
	cin >> n >> m;
	for(ll i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
//	for(ll i = 1;i <= n;i ++)
//		cout << a[i] << ' ';
	for(ll i = 2;i <= n;i ++){
		s += (a[i] - a[i-1]) * (i-l);
		//cout << s << ' ';
		if(s > m){
			mx = max(i-l,mx);
			//cout<< i << ' ' << l << ' ' << s << '\n';
			while(s > m){
				s -= a[i] - a[l],l ++;
			}
		}
	}
	cout << mx;
	return 0;
}


