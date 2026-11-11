#include <bits/stdc++.h>
using namespace std;
int a[200010];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "r", stdout);
	int n, ans = 0;
	string s;
	cin >> n;
	for(int i=1; i<=n; i++){
		string c;
		cin >> a[i] >> c;
		while(a[i] != 0){
			a[i]--;
			s += c;
		}
	}
	int l = s.size();
	for(int i=0, j=l-1; i<j; i++, j--){
		if(s[i] != s[j]) ans++;
	}
	cout << ans << endl;
}
