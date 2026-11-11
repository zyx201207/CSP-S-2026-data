#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int len;
int ans;
int k[200005],e[200005];
string s;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		int x;
		char y;
		cin >> x >> y;
		for(int j = 1; j <= x; j ++){
			s += y;
		}
		len += x;
		
	}
	for(int i = 0; i < (len / 2); i ++){
		if(s[i] != s[len - i - 1]){
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
