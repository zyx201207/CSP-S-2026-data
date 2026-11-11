#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; scanf("%d", &n);
	string s = "";
	long long len = 0;
	for(int i = 1; i <= n; i++){
		long long a;
		char c;
		scanf("%lld", &a);
		cin >> c;
		len += a;
		while(a--){
			s.push_back(c);
		}
	}
	int ans = 0;
	for(int i = 0; i < len; i++){
		if(s[i] != s[len - i - 1]){
			ans++;
			s[i] = s[len - i - 1];
		}
	}
	cout << ans;
	return 0;
} 
