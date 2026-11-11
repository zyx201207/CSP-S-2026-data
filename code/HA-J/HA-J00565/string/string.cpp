#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N = 2e5+5;
pair<char, int> c[N];
signed main() {
	freopen("string.in","r", stdin);
	freopen("string.out","w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	c[0].second = 0;
	for (int i=1;i<=n;i++) {
		int h;
		cin>>h>>c[i].first;
		c[i].second = c[i-1].second + h; 
	}
	int maxn = c[n].second;
	int i = 1, j = n, ans=0;
	while(i!=j){
		int istart = c[i-1].second + 1, jstart = maxn - c[j].second + 1;
		int iend= c[i].second, jend = maxn - c[j-1].second;
		int start = max(istart, jstart),end = min(iend, jend);
		if (c[i].first != c[j].first) {
			ans += (end - start + 1);
		}
		if (iend > jend) j--;
		else i++;
	}
	cout<<ans;
	return 0;
}
