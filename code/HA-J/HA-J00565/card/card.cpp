#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5, M = 3e5+5;
int a[N], ans[M];
vector<int> pos[M];
int n,m;
bool d[N];
int main() {
	freopen("card.in","r", stdin);
	freopen("card.out","w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if (n <= 500) {
		for (int i=1;i<=n;i++) {
			vector<int> po;
			fill(d+1, d+m+1, 0);
			for (int j=i;j<=n;j++) {
				if (d[a[j]] == 1) {
					while(!po.empty()&&po.back() != a[j]) {
						d[po.back()] = 0;
						po.pop_back();
					}
					continue;
				}
				po.push_back(a[j]);
				d[a[j]] = 1;
			}
			for (int j=0;j<po.size();j++){
				ans[po[j]]++;
			}
		}
		for (int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	else {
		for (int i=1;i<=n;i++) {
			ans[a[i]] = i;
		}
		for (int i=1;i<=m;i++) {
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
