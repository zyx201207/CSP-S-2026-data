#include<bits/stdc++.h>

using namespace std;

long long n, m;
const int N = 5e5 + 10;
long long a[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	memset(a, -0x3f, sizeof(a));
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	bool pda = 1; bool pdb = 1;
	long long bg = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (i == 2){
			bg = a[i] - a[i - 1];
		}
		if (i >= 3){
			if (a[i] - a[i - 1] != bg){
				pdb = 0;
			}
		}
		if (a[i] != i){
			pda = 0;
		}
	}
	if (pda == 1){
		long long l = 1, r = m;
		while (l <= r){
			long long mid = (l + r) >> 1;
			if ((mid + 1) / 2 * mid > m){
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		} 
		cout << min(n, r + 1);
		return 0;
	}
	if (pdb == 1){
		long long l = 1, r = m;
		while (l <= r){
			long long mid = (l + r) >> 1;
			if ((mid * bg + bg) * mid / 2 > m){
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		} 
		cout << min(n, r + 1);
		return 0;	
	}
	sort(a + 1, a + 1 + n);
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++){
		long long t = 0;
		int jg = 1; 
		for (int j = i - 1; j >= 1; j--){
			if (t + a[i] - a[j] > m){
				break;
			}
			t = t + a[i] - a[j];
			jg ++;
		}
		long long to = a[i];
		i ++;
		while (a[i] == to){
			i++;
			jg ++;
		}
		i--;
		ans = max(ans, jg);
	}
	cout << ans;		
	return 0;
}
