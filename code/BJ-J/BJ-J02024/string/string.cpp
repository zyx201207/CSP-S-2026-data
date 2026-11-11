#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll x;
char c;
string l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x >> c;
		for(int j = 1;j <= x;j++){
			l += c;
		}
	}
	ll ans = 0;
	for(int i = 0;i < l.size() / 2;i++)
		if(l[i] != l[l.size() - 1 - i]) ++ans;
	cout << ans;
	return 0;
}