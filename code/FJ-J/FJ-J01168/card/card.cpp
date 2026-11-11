#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=3e5+10;
const int M=5e5+10;
int ans[5050][3030],a[M],lst[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n,m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	if (m==1) {
		cout << n;
		return 0;
	}
	if (n>5000&&m<=2) {
		int ans[200010][5],a[M],lst[N];
		memset(ans, 0,sizeof ans);
		memset(a,0,sizeof a);
		memset(lst,0,sizeof lst);
		for (int i=n; i>=1; i--) {
			if (!lst[a[i]]) {
				lst[a[i]]=i;
				for (int j=1; j<=m; j++) {
					ans[i][j]=ans[i+1][j];
				}
				ans[i][a[i]]++;
			} else {
				for (int j=1; j<=m; j++) {
					ans[i][j]=ans[lst[a[i]]][j];
				}
				lst[a[i]]=i;
			}
		}
		for (int i=1; i<=m; i++) {
			int sum=0;
			for (int j=1; j<=n; j++) {
				sum+=ans[j][i];
			}
			cout << sum << ' ';
		}
		return 0;
	}
	for (int i=n; i>=1; i--) {
		if (!lst[a[i]]) {
			lst[a[i]]=i;
			for (int j=1; j<=m; j++) {
				ans[i][j]=ans[i+1][j];
			}
			ans[i][a[i]]++;
		} else {
			for (int j=1; j<=m; j++) {
				ans[i][j]=ans[lst[a[i]]][j];
			}
			lst[a[i]]=i;
		}
	}
	for (int i=1; i<=m; i++) {
		int sum=0;
		for (int j=1; j<=n; j++) {
			sum+=ans[j][i];
		}
		cout << sum << ' ';
	}
	return 0;
}
