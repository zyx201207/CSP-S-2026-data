#include<iostream>
#include<vector>
#define int unsigned long long
using namespace std;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s = "";
	int n;
	cin>>n;
	while(n--) {
		int a;
		char c;
		cin>>a>>c;
		while(a--) {
			s.push_back(c);
		}
	}
	int sz = s.size();
	int r = sz/2+(sz%2);
	int l = r;
	int ans = 0;
	for(; r<=sz; ) {
		if(s[r-1]!=s[l-1]) {
			ans++;
		}
		r++;
		l--;
	}
	cout<<ans;
	return 0;
}

