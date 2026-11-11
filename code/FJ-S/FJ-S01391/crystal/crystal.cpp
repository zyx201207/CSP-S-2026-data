#include<bits/stdc++.h>
using namespace std;
int n;
long long sum[500005], a[500005], ans, head, tail, cnt, m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i];
	}
	head = 1;
	for(int i = 1; i <= n; i++){
		tail = i;
		cnt = (a[tail]*(tail-head+1)-(sum[tail]-sum[head-1]));
		while(cnt > m){
			head++;
			cnt = (a[tail]*(tail-head+1)-(sum[tail]-sum[head-1]));
		}
		long long len = tail - head + 1;
		ans = max(ans, len);
	}
	cout << ans;
	return 0;
}