#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	vector<pair<long long, char> > a(n);
	for(auto &i : a){
		cin >> i.first >> i.second;
	}
	int l = 0, r = n-1;
	long long ans = 0;
	while(--n){
		if(a[l].first > a[r].first){
			if(a[r].second != a[l].second) ans += a[r].first;
			a[l].first -= a[r].first;
			r--;
		}
		else {
			if(a[r].second != a[l].second) ans += a[l].first;
			a[r].first -= a[l].first;
			l++;
		}
	}
	cout << ans;
} 

