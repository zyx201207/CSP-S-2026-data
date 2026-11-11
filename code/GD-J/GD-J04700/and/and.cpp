#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a + n);
	if(m == 1){		
		cout << a[n - 1];
	}
	else if(n == m){
		ll sum = a[0]&a[1];
		for(int i = 2;i < n;i++){
			sum = sum&a[i];
		}
		cout << sum;
	}
	else if(m == 2){
		ll sum = 0;
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				sum = max(sum,(a[i]&a[j]));
			}
		}
		cout << sum;
	}
	else{
		cout << a[n - m];
	}
	return 0;
}
