#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n;double m;
	cin >> n >> m;
	
	vector<long long> a(n);
	vector<double> b(n);
	cin >> a[0];
	for(int i = 1;i < n;i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	b[0] = a[0];
	for(int i = 1;i < n;i++) {
		b[i] = b[i - 1] + a[i];
	}
	
	double ans = 0;
	for(double i = 1;i < n;i++)
	{
		double cnt;
		
		if(m >= (double)((i - 1) * a[i]) - b[i - 1]) {
			cnt = i;
		}
		ans = max(ans, cnt + 1);
	}
	
	cout << ans;
	
	return 0;
}
