#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, char> > a(n+1);
	for (int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
	int l=1, r=n, ans=0, flag;
	pair<int, char> fnt={0, 'a'}, ed={0, 'a'};
	while (l<=r) {
		if (fnt.first==0) {
			fnt.first=a[l].first;
			fnt.second=a[l].second;
			l++;
		} else {
			ed.first=a[r].first;
			ed.second=a[r].second;
			r--;
		}
		flag=min(fnt.first, ed.first);
		if (fnt.second!=ed.second) ans+=flag;
		fnt.first-=flag;
		ed.first-=flag;
	}
	cout << ans << endl;
	return 0;
}
