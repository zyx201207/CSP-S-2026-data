#include<bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 5e5+5;

int a[MAX_N];

int n;
int m;

int l,r;
long long used;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for (int i=0; i < n; i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	while(r<n) {
		r++;
		long long now = 0;
		now = used+(a[r]-a[r-1])*(r-l);
		while (now>m) {
			l++;
			now = now-(a[r]-a[l]);
		}
		used = now;
		ans = max(ans,r-l+1); 
	}
	cout<<ans;
	return 0;
}
