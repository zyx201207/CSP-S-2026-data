#include<iostream>
#include<vector>
#define int unsigned long long
using namespace std;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> cards(n+1);
	for(int i=1; i<=n; i++) {
		cin>>cards[i];
	}
	vector<int> ans(m+1);
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			for(int k=n; k>=j; k--) {
				if(cards[j]==cards[k]) {
					j=k;
					break;
				}
			}
			ans[cards[j]]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<' ';
	}
	return 0;
}

