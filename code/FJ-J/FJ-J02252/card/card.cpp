#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
const int M = 3e5 + 10;
ll n, m;
ll s[N];
ll b[N];
ll ans[M];
stack<ll> a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> s[i];
	for(int i = 1;i <= n;i++) {
		for(int j = i;j <= n;j++) {
			ll x = b[s[j]];
			cout<<"x:"<<x<<" ";
			if (x != 0){
				while (a.top() != s[j]){
					b[a.top()]--;
					a.pop();
				}
				b[a.top()]--;
				a.pop();
			}
			cout<<"j:"<<j<<" ";
			cout<<"s[j]:"<<s[j]<<" ";
			cout<<"b[s[j]]:"<<b[s[j]]<<"\n";
			a.push(s[j]);
			b[1]=1;
			b[s[j]]=x+1;
		}
		while (a.size() > 0) {
			ans[a.top()]++;
			a.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
