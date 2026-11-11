#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500001],cnt[300001];
bool f[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	stack<ll> s;
	for (ll i = 1;i <= n;i++) cin >> a[i];
	for (ll i = 1;i <= n;i++){
		memset(f,0,sizeof f);
		for (ll j = i;j <= n;j++){
			if (f[a[j]]){
				while (s.top() != a[j]) s.pop();
			}
			else {
				s.push(a[j]);
				f[a[j]] = 1;
			}
		}
		memset(f,0,sizeof f);
		while (!s.empty()){
			f[s.top()] = 1;
			s.pop();
		}
		for (ll j = 1;j <= m;j++) if (f[j]) cnt[j]++;
	}
	for (ll i = 1;i <= m;i++) cout << cnt[i] << " ";
	return 0;
}
