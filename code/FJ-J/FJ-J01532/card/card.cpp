#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, check;
int a[500005];
int ans[300005];
vector<int> v;
bool find(int x) {
	for(int i = 0 ; i < v.size() ; i++) {
		if(v[i] == x) {
			check = v.size() - i;
			return true;	
		}
	}
	return false;
}
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	for(int i = 1 ; i <= n ; i++) {
		v.clear();
		for(int j = i ; j <= n ; j++) {
			if(v.empty()) {
				v.push_back(a[j]);
			}else {
				if(find(a[j])) {
					while(check--) v.pop_back();
				}
				v.push_back(a[j]);
			}
		}
		for(int i = 0 ; i < v.size() ; i++) {
			ans[v[i]]++;
		}
	}
	for(int i = 1 ; i <= m ; i++) {
		printf("%lld ", ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
