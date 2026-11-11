#include<bits/stdc++.h>
using namespace std;
long long n, m, minn, maxn, last_ans = 0, ans;
long long a[500024];
bool cmp(long long a, long long b){
	return a > b;
}
long long check(long long k){
	long long mm = m, cnt = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] <= k){
			if (k - a[i] <= mm){
				mm -= (k - a[i]);
				cnt++;
			}else{
				break;
			}
		}
	}
	return cnt;
}
int main()
{
     freopen("crystal.in", "r", stdin);
     freopen("crystal.out", "w", stdout);
     bool flag = 1;
     cin >> n >> m;
     for (long long i = 1; i <= n; i++){
		 cin >> a[i];
	 }
	 sort(a + 1, a + n + 1, cmp);
	 if (n == 1){
		 cout << a[1];
		 return 0;
	 }
	 long long v = a[1] - a[2];
	 for (long long i = n; i >= 2; i--){
		 if (a[i] - a[i - 1] != v){
			 flag = 0;
		 }
	 }
	 if (flag){
		 for (int i = 1; i <= n; i++){
			 if (m - v * (i - 1) >= 0){
				 m -= v * (i - 1);
				 last_ans++;
			 }
		 }
		 last_ans++;
		 cout << last_ans << endl;
		 return 0;
	 }
	 minn = a[n];
	 maxn = a[1];
	 long long l = minn, r = maxn;
	 while (l <= r){
		long long mid = l + (r - l) / 2;
		ans = check(mid);
		if (ans > last_ans){
			last_ans = ans;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	 }
	 cout << last_ans << endl;

     return 0;
}
