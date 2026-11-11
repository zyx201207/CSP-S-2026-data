#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5;
int n,mx,cnt;
ll m,a[N + 5],sum;
int main(int argc, char **argv){
#ifndef LOCAL
	freopen("crystal.in","r",stdin);
#endif
#ifndef LOCAL
	freopen("crystal.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++){
		sum += (a[i] - a[i - 1]) * cnt;
		while (cnt && sum > m){
			sum -= a[i] - a[i - cnt];
			cnt--;
		}
		cnt++;
		mx = max(mx,cnt);
	}
	cout << mx;
	return 0;
}

