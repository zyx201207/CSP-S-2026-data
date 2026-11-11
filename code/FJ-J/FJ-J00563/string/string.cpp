#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
		while(n--){
			int m;
			cin >> m;
			char a;
			cin >> a;
			for(int i = 1; i <= m; i++){
				s += a;
			}	
		}
		long long cnt = 0;
		for(int i = 0; i <= s.size()/2; i++){
			if(s[i] != s[s.size()-1-i]){
				cnt++;
			}
		}
		cout << cnt;
	return 0;
}
