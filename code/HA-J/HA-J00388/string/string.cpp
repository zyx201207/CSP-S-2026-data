#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 5;

int n, a[N];
char c[N];
ll len;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i(1); i <= n; i++){
		cin >> a[i] >> c[i];
		len += a[i];
	}
	int j = n;
	ll l = 0, r = len + 1, rest = a[j], ans = 0;
	for(int i(1); l <= len / 2 && i <= n; i++){
		ll decl = min(l + a[i], len / 2) - l;
		l += decl;
		ll decr = 0, cur = 0;
//		printf("decl=%lld\n",decl);
		while(decr < decl){
			cur = min(rest, decl - decr);
//			printf("decr=%lld cur=%lld ans=%lld\n",decr,cur,ans);
			if(c[j] != c[i]) ans += cur;
			r -= cur;
			rest -= cur;
			decr += cur;
			if(rest == 0){
				j--;
				rest = a[j];
			}
		}
	}
	cout << ans;
	return 0;
} 
