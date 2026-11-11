#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector < ll > a(n + 1);
	vector < ll > b(n + 1);
	ll sum = 0;
	for(int i = 1;i <= n;i++){
		char c;
		cin >> a[i] >> c;
		b[i] = c - 'a' + 1;
		sum += a[i];	
	}
	int i = 1,j = n;
	ll ans = 0;
	ll site = 0;
	while(i < j){
		if(a[i] == a[j]){
			ans += (b[i] == b[j] ? 0 : a[i]);
			site += a[i];
			i++;
			j--;
			continue;
		}
		if(a[i] < a[j]){
			site += a[i];
			ans += (b[i] == b[j] ? 0 : a[i]);
			a[j] -= a[i];
			i++; 
			continue;
		}
		if(a[i] > a[j]){
			ans += (b[i] == b[j] ? 0 :a[j]);
			a[i] -= a[j];
			j--;
			continue;
		}
	}
	cout << ans;
	return 0;
}
