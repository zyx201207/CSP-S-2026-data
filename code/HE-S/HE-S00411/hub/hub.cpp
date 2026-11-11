#include<bits/stdc++.h>
using namespace std;
vector<int> v[500001];
int c,t,n,k,x,y,s;
bool st[500001];
void dfs(int step,int bj) {
	if(step > k) {
		s = min(s,bj);
		return;
	}
	if(bj > s) return;
	for(int i = 1;i <= n;i++) if(!st[i]) dfs(step+1,bj);
	return;
}
int main () {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1;i < n;i++) {
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		s = 1e9;
		dfs(1,1);
		cout << s << endl;
	}
	return 0;
}
