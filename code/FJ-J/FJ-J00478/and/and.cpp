#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int pow2[21] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
int sz[200005], sn[200005];
int n, m;
int ans;
bool speA() {
	for(int i = 1; i <= n; i ++) {
		bool flag;
		for(int j = 1; j <= 20; j ++) {
			if(a[i] + 1 == pow2[j]) {
				flag = true;
				break;
			}
		}
		if(! flag) {
			return false;
		}
	}
	return true;
}
bool speC() {
	for(int i = 1; i <= n; i ++) {
		if(a[i] >= 4) {
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if(m == n) {
		for(int i = 1; i <= n; i ++) {
		    ans &= a[i];
	    }
	    cout << ans;
	    return 0;
	}
	else if(m == 1) {
		for(int i = 1; i <= n; i ++) {
		    ans = max(ans, a[i]);
	    }
	    cout << ans;
	    return 0;
	}
	else if(m == 2) {
		for(int i = 1; i <= n; i ++) {
		    for(int j = i + 1; j <= n; j ++) {
		    	ans = max(ans, (a[i] & a[j]));
			}
	    }
	    cout << ans;
	    return 0;
	}
	else if(m == n - 1) {
		for(int i = 1; i <= n; i ++) {
		    sz[i] = (sz[i - 1] & a[i]);
	    }
	    for(int i = n; i >= 1; i --) {
		    sn[i] = (sn[i + 1] & a[i]);
	    }
	    for(int i = 1; i <= n; i ++) {
		    ans = max(ans, (sz[i - 1] & sn[i + 1]));
	    }
	    cout << ans;
	    return 0;
	}
	else if(speA()) {
		sort(a + 1, a + 1 + n);
		cout << a[n - m + 1];
		return 0;
	} 
	else if(speC()) {
		int cnt3, cnt2, cnt1;
		for(int i = 1; i <= n; i ++) {
			if(a[i] == 3) {
				cnt3 ++;
			}
			if(a[i] == 2) {
				cnt2 ++;
			}
			if(a[i] == 1) {
				cnt1 ++;
			}
		}
		if(m > cnt3 + cnt2) {
			if(m > cnt3 + cnt1) {
				cout << 0;
			}
			else {
				cout << 1;
			}
		}
		else if(m > cnt3) {
			cout << 2;
		}
		else {
			cout << 3;
		}
		return 0;
	}
	else {
		sort(a + 1, a + 1 + n);
		for(int i = n; i >= n - m + 1; i --) {
			ans &= a[i];
		}
		cout << ans;
	}
	return 0;
}

