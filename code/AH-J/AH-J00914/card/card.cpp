#include <bits/stdc++.h>
using namespace std;
int a[500005];
map <int,bool> mp;
map <int,int> ans;
int main () {
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) {
		stack <int> s;
		for (int j=i;j<=n;j++) {
			int now=a[j];
			if (mp[now]) {
				while (!s.empty() && s.top()!=now) {
					mp[s.top()]=0;
					s.pop();
				}
			} else {
				mp[now]=1;
				s.push(now);
			}
		}
		while (!s.empty()) {
			ans[s.top()]++;
			s.pop();
		}
		mp.clear();
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
