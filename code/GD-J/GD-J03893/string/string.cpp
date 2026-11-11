#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
struct node{
	ll a;
	char c;
};
int n;
ll ans;
node s[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i].a >> s[i].c;
	int l = 1, r = n;
	while(l < r){
		ll b = min(s[l].a, s[r].a);
		if (s[l].c != s[r].c)
			ans += b;
		bool zuo = 0, you = 0;
		if (s[l].a >= s[r].a){
			you = 1;
		}
		if (s[l].a <= s[r].a){
			zuo = 1;
		}
		if (zuo){
			s[r].a -= b;
		}
		if (you){
			s[l].a -= b;
		}
		if (zuo){
			l++;
		}
		if (you){
			r--;
		}
	}
	cout << ans;
	return 0;
}

