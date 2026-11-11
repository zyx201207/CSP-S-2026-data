#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+5;
int a,n,cnt;
string s;
char c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> c;
		for(int j = 1;j <= a;j++) s = s + c;
	}
	int len = s.length();
//	cout << s << "\n";
	for(int i = 0;i < len / 2 + len % 2;i++){
		if(s[i] != s[len - i - 1]){
//			cout << s[i] << " " << s[len-i-1] << "\n";
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}
