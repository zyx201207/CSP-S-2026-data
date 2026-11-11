#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	string s,r;
	cin >> n >> s >> m >> r;
	if(n == m){
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	if(s[0]+s[1]==r[0]+r[1]){
		cout << 1; 
	} else {
		cout << "000";
		return 0;
	}
	
	if(s[2] + r[2] == 138 || s[2] + r[2] == 133 || s[2] + r[2] == 131 || s[2] + r[2] == 132) cout << 1;
	else cout << 0;
	if(s[2] + r[2] == 138 || s[2] + r[2] == 133 || s[2] + r[2] == 131) cout << 1;
	else cout << 0;
	return 0;
}
