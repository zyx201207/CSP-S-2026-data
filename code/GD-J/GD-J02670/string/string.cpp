#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	while(n--){
		int a;
		char c;
		cin >> a >> c;
		for (int i=1;i<=a;i++)
			s=s+c;
	}
	long long ans=0;
	for (int i=0;i<s.size()/2;i++){
		if (s[i]!=s[s.size()-1]) ans++;
	}
	cout << ans;
	return 0;
}
