//GZ-J00519,lijunshen 
#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n;
struct S{
	int b, e;
	char c;
}s[200005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int len, e = 0;
	for (int i = 0;i < n;i++){
		cin >> len >> s[i].c;
		s[i].b = e;
		s[i].e = s[i].b+len-1;
		e = s[i].e+1;
	}
	int l = 0, r = n-1;
	int lpos = 0, rpos = e-1;
	int lenl, lenr;
	int ans = 0;
	while (l < r){
		lenl = s[l].e-lpos+1;
		lenr = rpos-s[r].b+1;
		if (s[l].c != s[r].c){
			ans += min(lenl, lenr);
		}
		if (lenl == lenr)l++, r--;
		else if (lenl > lenr)r--;
		else l++;
		lpos += min(lenl, lenr);
		rpos -= min(lenl, lenr);
	}
	cout << ans;
	return 0;
}
