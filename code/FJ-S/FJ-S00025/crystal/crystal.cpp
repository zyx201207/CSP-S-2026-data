#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define per(i,a,b) for(int i = (a);i >= (b);i--)

using namespace std;

typedef long long ll;

const int N = 500005;

int n;
ll m;
ll a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	rep(i,1,n) cin >> a[i];
	sort(a + 1,a + n + 1);
	int j = 1;
	ll cur = 0;
	int ans = 0;
	rep(i,1,n){
		cur += (i - j) * (a[i] - a[i - 1]);
		while(cur > m){
			cur -= a[i] - a[j];
			j++;
		}
		ans = max(ans,i - j + 1);
	}
	cout << ans;
	return 0;
}

