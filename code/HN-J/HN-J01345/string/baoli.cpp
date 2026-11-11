#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
#define __low lower_bound
#define __upp upper_bound
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+5;

string s;
int n, a[N], ans;
char c[N];

int main(){
	freopen("string.in", "r", stdin);
	freopen("baoli.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for(int j = 0; j < a[i]; j++){
			s += c[i];
		}
	}
	for(int l = 0, r = s.size()-1; l < r; l++, r--){
		if(s[l] != s[r]) ans++;
	}
	cout << ans << "\n";
	
	return 0;
}
