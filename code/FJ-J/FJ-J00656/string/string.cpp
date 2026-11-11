#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,ans,sum;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	sum = n;
	for (ll i = 1;i <= n;i++){
		cin >> a >> c;
		sum += a;
		for (int i = 1;i <= a;i++){
			s += c;
		}
	}
	for (ll i = 0;i < s.size();i++){
		for (ll j = s.size()-1;j >= 0;j--){
			if (s[i] != s[j])ans++;
		}
	}
	cout << ans/sum;
	return 0;
}
