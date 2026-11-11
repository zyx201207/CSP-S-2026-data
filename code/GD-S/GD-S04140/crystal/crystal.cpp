#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
long long a[N], n, maxi, pre[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++){
		pre[i - 1] = a[i] - a[i - 1];
	}
	deque<int>v;
	int sum = 0, cnt = 0;
	for(int i = 1; i <= n; i++){
		v.push_back(pre[i]);
		sum += pre[i] * v.size();
		cnt += pre[i]; 
		while(sum > m && v.size()){
			sum -= cnt;
			cnt -= v.front();
			v.pop_front();
		}
//		cout << sum << " " << cnt << endl;
		maxi = max(maxi, (long long)(v.size() + 1));
	}
	cout << maxi;
	return 0;
}
