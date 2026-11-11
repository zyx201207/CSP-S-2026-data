#include<bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
long long a[N];
long long Pow[N][35], b[N];
pair<long long, long long>ans[N];
bool cmp(pair<long long, long long>x, pair<long long, long long>y){
	if(x.first != y.first)return x .first > y.first;
	return x.second > y.second;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)cin >> a[i];
	for(long long i = 1; i <= n; i++)b[i] = a[i];
	for(long long i = 1; i <= n; i++){
		long long tot = 30;
		while(a[i]){
			if(a[i] & 1)Pow[i][tot] = 1;
			tot--;
			a[i] >>= 1;
		}
	}
	for(long long j = 1; j <= n; j++){
		ans[j].second = b[j];
	}
	for(long long i = 0; i <= 30; i++){
		for(long long j = 1; j <= n; j++){
			if(Pow[j][i] == 1){
				ans[j].first++;
			}
		}
	}
	sort(ans + 1, ans + n + 1, cmp);
	long long c = ans[1].second;
	for(long long i = 1; i <= m; i++){
		c &= ans[i].second;
	}
	cout << c;
	return 0;
}
