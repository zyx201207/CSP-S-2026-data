#include <bits/stdc++.h>
#define lint unsigned long long 
using namespace std;
lint n,m;
lint t;
vector<lint> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(lint i=1;i<=n;i++) {
		lint nn;
		cin >> nn;
		v.push_back(nn);
	}
	sort(v.begin(),v.end());
	t = v[n-1];
	for(lint i=1;i<m;i++) {
		t = v[n-i-1] & t;
	}
	cout << t;
	return 0;
}
