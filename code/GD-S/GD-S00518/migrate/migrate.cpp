#include <bits/stdc++.h>
using namespace std;

long long c, t;
long long n, d, x[2000005], dif;
bool speA = 1;
long long pos[305], neg[305];
void mian(){
	cin >> n >> d;
	speA = 1, dif = 0;
	if(n == 1)
		speA = 0;
	for(int i = 1;i <= n;i++){
		cin >> x[i];
		if(i == 1)
			continue;
		if(dif == 0)
			dif = x[i] - x[i - 1];
		if(x[i] - x[i - 1] != dif)
			speA = 0;
	}
	if(speA && n > 300){
		if(d / dif <= 1)
			cout << 0 << endl;
		else
			cout << max(n - ((d / dif) * 2) + 1, 0ll) << endl;
		return ;
	}
	if(x[n] - x[1] <= d * 2){
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			if(x[n] - x[i] <= d)
				break;
			int j = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1, r = upper_bound(x + 1, x + n + 1, x[j - 1] + d) - x - 1, l = upper_bound(x + 1, x + n + 1, x[j - 2] + d) - x;
			ans += r - l + 1;
		}
		cout << ans << endl;
		return ;
	}
	int ans = 0;
	for(int i = 1;i < n;i++)
		for(int j = i + 3;j <= n;j++){
			if(x[i + 1] - x[i] > d || x[j] - x[j - 1] > d)
				continue;
			long long cnt = 0, p = x[i], tf = 1, ccnt, tot = 0;
			for(int k = i + 1;k < j && tf;k++){
				if(x[k] - p <= d && x[k + 1] - p > d)
					cnt++, pos[cnt] = k, p = x[k];
				if(x[k] - p > d)
					tf = 0;
			}
			p = x[j], ccnt = cnt;
			for(int k = j - 1;k > i && tf;k--){
				if(p - x[k] <= d && p - x[k - 1] > d)
					neg[cnt] = k, cnt--, p = x[k];
				if(p - x[k] > d)
					tf = 0;
			}
			if(!tf)
				continue;
			for(int k = 1;k <= ccnt;k++)
				tot += abs(pos[k] - neg[k]);
			if(tot == 1)
				ans++;
		}
	cout << ans << endl;
	return ;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	for(int T = 1;T <= t;T++)
		mian();
	return 0;
}
