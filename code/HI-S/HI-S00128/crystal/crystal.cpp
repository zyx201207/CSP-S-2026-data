# include <bits/stdc++.h>

using namespace std;

# define int long long

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n, 0);
	
	bool change = false;
	bool check = true;
	
	int d = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		
		if (i > 0) {
			if (change) {
				if (a[i] - a[i - 1] != d) {
					check = false;
				}
			}
			
			d = a[i] - a[i - 1];
			change = true;
		}
	}
	
	if (check) {
		int cnt = 0;
		int cresult = 1;
		int i = d;
		
		while (true) {
			if (cnt > m) {
				break;
			}
			
			cnt += i;
			i += d;
			
			if (cnt > m) {
				break;
			}
			
			cresult++;
			if (cresult > n) {
				cresult--;
				break;
			} 
		}
		
		cout << cresult;
		return 0;
	}
	
	sort(a.begin(), a.end());
	
	int result = 1;
	
	int copy_m;
	int temp;
	int take;
	int cnt;
	
	for (int i = n - 1; i >= 0; --i) {
		copy_m = m;
		cnt = 0;
		take = 0;
		temp = 1;
		
		for (int j = i - 1; j >= 0; --j) {
			cnt = abs(a[i] - a[j]);
			
			take = min(copy_m, cnt);
			
			cnt -= take;
			copy_m -= take;
			
			if (copy_m == 0 && cnt > 0) {
				break;
			} else if (copy_m >= 0 && cnt == 0) {
				temp++;
			}
		}
		
		result = max(result, temp);
	}
	
	cout << result;
	return 0;
}
