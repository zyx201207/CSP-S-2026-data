#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,a[N];
char c[N];
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for(int j = 0; j < a[i]; j++) s += c[i];
	}
	for(int l = 0,r = s.size() - 1; l < r; l++,r--){
		if(s[l] != s[r]) ans++;
	}
	cout << ans;
	return 0;
}