#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define int ll
#define inf (1e18 + 10)
int n, a;
char c;
string s;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	if(n <= 1){
		cout << 0;
		return 0;
	}else if(n <= 2){
		for(int i = 0;i < n;i ++){
			cin >> a >> c;
			while(a --){
				s += c;
			}
		}
		int cnt = s.size() - 1;
		bool flag = 0;
		for(int i = 0;i < s.size() / 2;i ++){
			if(s[i] != s[cnt]){
				flag = 1;
			}
			cnt --;
		}
		if(flag == 0){
			cout << 0;
			return 0;
		}else{
			cout << s.size() / 2;
			return 0;
		}
	}
	while(n --){
		cin >> a >> c;
		while(a --){
			s += c;
		}
	}
	string s2;
	if(s.size() & 1){
		for(int i = 0;i < s.size() / 2 + 1;i ++){
			s2 += s[i];
		}
		for(int i = s2.size() - 2;i >= 0;i --){
			s2 += s2[i];
		}
		int ans = 0;
		for(int i = 0;i < s2.size();i ++){
			if(s[i] != s2[i]){
				ans ++;
			}
		}
		cout << ans;
		return 0;
	}else{
		for(int i = 0;i < s.size() / 2;i ++){
			s2 += s[i];
		}
		for(int i = s2.size() - 1;i >= 0;i --){
			s2 += s2[i];
		}
		int ans = 0;
		for(int i = 0;i < s2.size();i ++){
			if(s[i] != s2[i]){
				ans ++;
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
} 
