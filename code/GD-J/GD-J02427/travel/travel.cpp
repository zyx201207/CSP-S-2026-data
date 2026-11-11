#include<bits/stdc++.h>
using namespace std;
const int N = 1;
int a, b, f[10];
string s, t;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a;cin >> s;cin >> b;cin >> t;
	
	f[1] = (a == b);
	
	f[2] = (s[0]==t[0] && s[1]==t[1] && f[1]);
	
	f[3] = f[4] = 0;
	if(s[2] == 'A' && t[2] == 'B' && f[2]) f[3] = 1, f[4] = 1;
	if(s[2] == 'B' && t[2] == 'A' && f[2]) f[3] = 1, f[4] = 1;
	
	if(s[2] == 'B' && t[2] == 'C' && f[2]) f[3] = 1, f[4] = 1;
	if(s[2] == 'C' && t[2] == 'B' && f[2]) f[3] = 1, f[4] = 1;
	
	if(s[2] == 'A' && t[2] == 'C' && f[2]) f[3] = 1, f[4] = 0;
	if(s[2] == 'C' && t[2] == 'A' && f[2]) f[3] = 1, f[4] = 0;
	
	if(s[2] == 'D' && t[2] == 'F' && f[2]) f[3] = 1, f[4] = 1;
	if(s[2] == 'F' && t[2] == 'D' && f[2]) f[3] = 1, f[4] = 1;
	
	for(int i = 1; i <= 4; i++) cout << f[i];
	return 0;
} 
