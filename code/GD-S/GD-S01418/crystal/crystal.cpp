#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll a[N], diff[N];
int ans = 1;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	bool flag = true;
	auto t1 = clock();
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		diff[i] = a[i] - a[i-1];
		if(diff[i] != diff[i-1] && i > 2) flag = false;
	}
	if(flag){
		cout << floor(sqrt(abs(double(2*m)/double(diff[2]) + 0.25)) - 0.5) + 1;
	}else{
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++){
			if(clock() - t1 >= 900){
				break;
			}
			int k = m;
			int cur = 1;	
			int j = i-1;	
			while(j >= 1 && k-(a[i]-a[j]) >= 0){
				cur++;
				k -= (a[i] - a[j]);
				j--;
			}
			ans = max(cur,ans);
		}
		cout << ans;
	}
	return 0;
}
