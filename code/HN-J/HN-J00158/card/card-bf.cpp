#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 55, MAXM = 3e5 + 35;

int n, m;
int a[MAXN];
int cnt[MAXN];

int ans[MAXM];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
    	vector<int>stk;
    	for(int j = i; j <= n; j++) {
    		if(cnt[a[j]]) {
    			for(; stk.back() != a[j]; stk.pop_back())cnt[stk.back()]--;
			} else {
				stk.push_back(a[j]);
				cnt[a[j]]++;
			}
		}
		for(int v = 1; v <= m; v++) {
			if(cnt[v]) {
				ans[v]++;
				cnt[v] = 0;
			}
		}
	}
	for(int v = 1; v <= m; v++) {
		cout << ans[v] << " \n"[v == m];
	}
    return 0;
}
