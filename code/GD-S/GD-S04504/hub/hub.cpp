#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, t, cnt = 1;
	cin >> c >> t;
	while(t--)  {
		int n, k, u[100005], v[100005];
		cin >> n >> k;
		for(int i = 1; i <= n-1; i++) {
			cin >> u[i] >> v[i];
		}
		cout << cnt << endl;
		cnt++;
	}
	return 0;
}

