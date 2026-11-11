#include <bits/stdc++.h>
using namespace std;
char c[200010];
long long sum[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,a;
	char c;
	cin >> n;
	string s = "";
	for (int i = 1;i <= n;i++){
		cin >> a >> c;
		for (int j = 1;j <= a;j++){
			s += c;
		}
	}
	int len = s.length();
	for (int i = 0;i <= len / 2 ;i++){
		int j = len - 1 - i;
		if (s[i] != s[j]){
			RP++;
		}
	}
	cout << RP;
	return 0;
}
