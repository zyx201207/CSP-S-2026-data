#include <bits/stdc++.h>
using namespace std;
#define int long long
string a, b, c, d;
int vis[5];
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> a >> b >> c >> d;
	//1
	if(a == c) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	//2
	bool flag = true;
	for(int i = 0;i <= 1;i++) if(b[i] != d[i]) flag = false;
	if(flag) cout << 1;
	else {
		cout << "000";
		return 0;	
	}
	//3
	if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C') vis[1]++;
	else vis[2]++;
	if(d[2] == 'A' || d[2] == 'B' || d[2] == 'C') vis[1]++;
	else vis[2]++;
	if(vis[1] > 1 || vis[2] > 1) cout << 1;
	else {
		cout << "00";
		return 0;	
	}
	//4
	if(b[2] + 1 == d[2] || b[2] - 1 == d[2]) cout << 1;
	else cout << 0;
	return 0;
}
