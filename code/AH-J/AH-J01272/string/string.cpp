#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n,ans=0;
	cin >> n;
	string s;
	for (int i=1;i<=n;i++){
		int t;
		char ch;
		cin >> t >> ch;
		for (int j=1;j<=t;j++) s += ch;
	}
	string ss = s;
	reverse(ss.begin(),ss.end());
	for (int i=0;i<s.length()/2;i++){
		if(s[i] != ss[i])ans++;
	}
	cout << ans << endl;
	return 0;
}
