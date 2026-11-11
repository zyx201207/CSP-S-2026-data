#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
int n,ans;
ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;++i) sum[i] = sum[i-1] + a[i];
	for(int i = 1,j = 1;i <= n;++i){
		while(j <= i && a[i] * (i-j+1) - (sum[i] - sum[j-1]) > m) ++j;
		ans = max(ans,i-j+1);
	}
	cout << ans << '\n';
	return 0;
}

/*
曾经，幻想中的城市，编不完的故事，依然没有成为现实。
如今，泛了黄的曾经，快愈合的陈病，偶尔只有夜里呻吟。

想尖叫，发不出讯号，困如笼中鸟，咆哮不是解药。
谁依靠，只剩我独遭，人烟如浪潮，将我困在墙角。
*/
