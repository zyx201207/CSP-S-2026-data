#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
long long ans;
string s;
char c[200005];
int main () {
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i ++) {
		cin>>a[i]>>c[i];
		for (int j = 0;j < a[i];j ++) s += c[i];
	}
	for (int i = 0;i < s.length();i ++) {
		ans += (s[i] != s[s.length() - i - 1]);
	}
	cout<<ans/2;
	fclose (stdin);
	fclose (stdout);
	return 0;	
}
