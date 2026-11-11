#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[555555];
int n, m;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	int last_ans = 0, last_use = 0;
	for(int i = 1; i <= n; i++){
		int p = i - last_ans;
		int tmp_ans = last_ans + 1;
		int over_use = m - last_use - last_ans * (a[i] - a[i - 1]);

		while(over_use < 0 && p >= 1 && p <= n){
			tmp_ans--;
			over_use += (a[i] - a[p]);
			p++;
		//	cout <<877777777777434;
		}
		
		//	cout << p <<"{{}}"<<i<< endl;
		ans = max(ans, tmp_ans);
		last_ans = tmp_ans;
		last_use = m - over_use;
	}
	cout << ans; 
	return 0;
} 
