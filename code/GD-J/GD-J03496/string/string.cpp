#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n;
	cin >> n;
	string s,ds;
	while (n--) {
		int a;
		char c;
		cin >> a >> c;
		while (a--) s.push_back(c);
	}
	long long ans=0;
	for (int i=s.size()-1;i>=0;i--) ds.push_back(s[i]);
	if (s==ds) {
		cout << 0;
		return 0;
	}
	for (int i=0,j=s.size()-1;i<j;i++,j--) {
		if (s[i]!=s[j]) ans++;
	}
	cout << ans;
	return 0;
}
