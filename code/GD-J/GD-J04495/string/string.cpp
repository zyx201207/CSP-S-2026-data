#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int cnt;
	char c;
};
const int N = 2e5+5;
node a[N] = {};
int prefix[N] = {};
signed main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n;i ++ )  {
		cin >> a[i].cnt >> a[i].c;
	}
	
	string s;
	
	for(int i = 1; i <= n;i ++ ) {
		for(int j = 1; j <= a[i].cnt ; j ++ ) {
			s += a[i].c;
		}
	}
	
	for(int i = 0;i < s.size()/2; i++ ) {
		if(s[i] != s[s.size()-i-1]) {
			ans++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}


