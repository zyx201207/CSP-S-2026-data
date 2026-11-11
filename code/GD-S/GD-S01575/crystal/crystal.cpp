#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using ll = long long;
using pll=pair<ll,ll>;
ll n , m , a[N],cnt=1;
queue<int> q;
bool count(int l , int r) {
	ll sum = 0;
	for(int i = l; i < r; i++) {
		sum+=a[r]-a[i];
	}
	return sum>m;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	q.push(1);
	for(int i = 2; i <= n; i++) {
		if(a[i]==a[i-1]) {
			cnt++;
			q.push(i);
			continue;
		}
		while(count(q.front(),i)&&!q.empty()) q.pop();
		q.push(i);
		ll cnt1=q.size();
		cnt=max(cnt,cnt1);
	}
	cout << cnt << '\n';
	return 0;
}
