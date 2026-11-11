#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin >> n;
	string s;
	while(n--){
		int a; cin >> a;
		char c; cin >> c;
		for(int i=1;i<=a;i++){
			s=s+c;
		}
	}
	int ans=0;
	for(int i=0;i<s.size();i++){
		int j=s.size()-i-1;
		if(s[i]!=s[j]) ans++;
	}
	cout << ans/2;
	
	
	return 0;
}
