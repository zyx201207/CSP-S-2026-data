#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
string s;
int n;
int a;
char b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while (n--){
		cin >> a >> b;
		for (int i = 0;i < a;i++){
			s+=b;
		}
	}
	long long ans = 0;
	for (int i = 0;i < s.size()/2;i++){
		if (s[i] != s[s.size()-i-1]){
			ans++;
		}
	}
	cout << ans;
}
