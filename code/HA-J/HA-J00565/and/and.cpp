#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, m;
int a[N], ans=0;
vector<int> c;
void dfs(vector<int> choices, int av) {
	if (choices.size() == m){
		ans = max(ans, av);
		return;
	}
	int j=0;
	int st = 1;
	if (!choices.empty()) st = choices[choices.size() - 1]+1;
//		cout<<st<<endl;
	for (int i=st;i<=n-(m-choices.size())+1;i++) {
		vector<int> s = choices;
		s.push_back(i);
		dfs(s, av & a[i]);
	}
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("and.in","r", stdin);
	freopen("and.out","w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	int maxx = 0;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if (n <= 20){
		dfs(vector<int>(), 2147483647);
	}
	else if (m == 1) {
		for (int i=1;i<=n;i++) {
			ans = max(ans, a[i]);
		}
	}
	else if (m == 2) {
		for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
	}
	else if (m == n) {
		ans = a[1];
		for (int i=2;i<=n;i++) {
			ans &= a[i];
		}
	}
	else {
		sort(a+1, a+n+1, cmp);
		ans = a[1];
		for (int i=2;i<=m;i++) {
			ans &= a[i];
		}
	}
	cout<<ans;
	return 0;
}
