#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll X = 1e8;
ll n, m, maxn, maxv, ans;
vector <ll> a;
int mm[200000005]; //数字， 出现次数
bool cmp(ll x, ll y){
	return x > y;
} 
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		ll x;
		cin >> x;
		x = x+X;
		a.push_back(x);
		mm[x]++; 
		if(mm[x] >= maxv){
			maxv = mm[x];
			maxn = x;
		}
	}
	sort(a.begin(), a.end(), cmp);
	//贪心
	for(int i=0; i<n; i++){
		if(a[i] <= maxn && m-(maxn-a[i]) >= 0){
			//cout << a[i] << ' ';
			ans++;
			m = m-(maxn-a[i]);
		}
	} 
	//cout << endl;
	cout << ans;
	//cout << endl << maxn << ' ' << maxv << endl;
	return 0;
}
