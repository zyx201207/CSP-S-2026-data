//40 pts
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool use[300005];
void solve1() {
	for (int i = 1;i<=n;i++)
		ans[a[i]] = i;
	for (int i = 1;i<=n;i++) cout<<ans[i]<<' ';
	exit(0);
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	bool bigger = 1;
	for (int i = 1;i<=n;i++) {
		cin>>a[i];
		if (a[i]>a[i+1]) bigger = 0;
	}
	if (bigger&&n>500) solve1();
	for (int i = 1;i<=n;i++) {
		deque <int> q;
		memset(use,0,sizeof use);
		for (int j = i;j<=n;j++) {
			if (use[a[j]]==0) {
				q.push_back(a[j]);
				use[a[j]] = 1;
			} else
				while (q.size()&&q.back()!=a[j]) {
					use[q.back()] = 0;
					q.pop_back();
				}
		}
		for (int j = 1;j<=m;j++)
			if (use[j]) ans[j]++;
	}
	for (int i = 1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
