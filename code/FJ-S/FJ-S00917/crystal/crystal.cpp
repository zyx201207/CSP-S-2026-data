#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int man = 500005;

int a[man];
ll dif[man];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	ll m;
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a,a + n);
	
	for(int i = 0; i < n; ++i){
		if(i + 1 < n) {
			dif[i] = a[i + 1] - a[i];
		}
	}
	
	ll ans = 1;
	ll sum;
	ll mm = m;
	ll ans1 = 1;
	for(int i = 1; i < n - 1; ++i){
		sum = 0;
		mm = m;
		ans1 = 1;
		for(int j = i - 1; j >= 0; --j){
			sum += dif[j];
			if(mm < sum){
				break;
			}
			else{
				mm -= sum;
				ans1++;
			}
		}
		ans = max(ans,ans1);
	}
	
	cout << ans << '\n';
	return 0;
}
