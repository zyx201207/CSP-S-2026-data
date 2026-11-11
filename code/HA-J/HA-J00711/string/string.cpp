#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N], ans;
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> c[i];
	string s;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < a[i]; j++)
			s += c[i];
	ll len = s.size();
	for(int i = 0, j = len - 1; i < len / 2, j > len / 2; i++, j--){
		if(s[i] != s[j]){
			ans++;
			s[j] = s[i];
		}
	}
	cout << ans;
	return 0;
}
