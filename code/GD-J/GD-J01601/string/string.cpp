#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		int x;
		char c;
		cin>>x>>c;
		while(x--) {
			s+=c;
		}
	}
	string t=s;
	reverse(t.begin(),t.end());
	int ans=0;
	for(int i=0; i<s.size(); i++) {
		if(t[i]!=s[i]) {
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
