#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> dp;
vector<int> p;
stack<int> w;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	dp=vector<int> (m+1,0);
	p=vector<int> (n+1,0);
	for (int i=1; i<=n; i++) {
		cin>>p[i];
	}
	for (int i=1; i<=n; i++) {
		vector<int> flag(m+1,0);
		while (!w.empty()) {
			w.pop();
		}
		for (int j=i; j<=n; j++) {
			if (flag[p[j]]!=0) {
				while (w.top()!=p[j]) {
					flag[w.top()]--;
					w.pop();
				}
			} else {
				w.push(p[j]);
				flag[p[j]]++;
			}

		}
		while (!w.empty()) {
			dp[w.top()]++;
			w.pop();
		}
	}

	for (int i=1; i<=m; i++) {
		cout<<dp[i]<<" ";
	}
	return 0;
}

