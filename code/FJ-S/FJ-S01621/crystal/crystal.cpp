#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 10;

ll a[N];
ll dist[N];
int n, m;
ll maxn = 0;
ll sum[N];

ll read(){
	ll x = 0, flag = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') flag = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * flag;
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		a[i] = read();
		maxn = max(maxn, a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	
	for(int i = 1; i <= n; i++){
		dist[i] = maxn - a[i];
		sum[i] = sum[i - 1] + dist[i];
//		cout << sum[i] << " ";
//		cout << a[i] << " " << dist[i] << endl;
	}
	
//	cout << endl;
	
	ll ans = 1;
	
	for(int i = 1; i <= n; i++){
		int res = 1;
		int l = i + 1; int r = n;
		if(l > r) continue ;
		while(l <= r){
//			cout << mid << " ";
			int mid = (l + r) >> 1;
//			cout << mid << " ";
//			cout << sum[mid] - sum[i] - (mid - i) * dist[i] << endl;
			if((sum[mid] - sum[i] - (mid - i) * dist[i]) <= m) l = mid + 1;
			else r = mid - 1;
		}
//		cout << i << " " << a[i] << " " << l - i << endl;
		ans = max(ans, 1ll * (l - i));
	}
	
	cout << ans << '\n';
	return 0;
}
