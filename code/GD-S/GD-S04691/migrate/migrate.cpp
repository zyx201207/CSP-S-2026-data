#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6;
int n,cnt,fst[N + 4],ans;
ll a[N + 5],d;
int main(int argc, char **argv){
	ios::sync_with_stdio(0),cin.tie(0);
#ifndef LOCAL
	freopen("migrate.in","r",stdin);
#endif
#ifndef LOCAL
	freopen("migrate.out","w",stdout);
#endif
	int id,t;
	cin >> id >> t;
	while (t--){
		cnt = 1;
		ans = 0;
		cin >> n >> d;
		for (int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for (int i = 2;i <= n;i++){
			while (a[i] - a[i - cnt] > d){
				fst[i - cnt] = i - 1;
				cnt--;
			}
			cnt++;
		}
		for (int i = n - cnt;i <= n;i++){
			fst[i] = n;
		}
		for (int i = 1;i <= n;i++){
			if (fst[i] - i == 2 && fst[i] != n)	ans += fst[i + 1] - fst[i];
		}
		cout << ans << '\n';
	}
	return 0;
}

