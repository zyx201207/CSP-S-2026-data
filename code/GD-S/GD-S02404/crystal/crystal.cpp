#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
long long m, mm;
int n;
long long a[maxn], ma = -0x3f3f3f3f3f3f3f3f, mi = 0x3f3f3f3f3f3f3f3f;
int ans;
bool flag = true;

//bool cmp(int a, int b){
//	return a > b;
//}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ma = max(a[i], ma);
		mi = min(a[i], mi);
		if(a[i] != i) flag = false;
	}
	sort(a + 1, a + n + 1);
	if(ma <= 100010){
		for(int i = mi; i <= ma; i++){
			mm = m;
			int cnt = 0;
			int j = upper_bound(a + 1, a + n + 1, i) - a;
			j--;
			for(; j >= 1; j--){
				long long cha = i - a[j];
//				if(i == 9) cout << mm << '\n';
				if(mm >= cha){
					mm -= cha;
					cnt++;
				}else{
					break;
				}
			}
			if(cnt > ans){
				ans = cnt;
//				cout << i << ' ' << cnt << '\n';
			}
		}
		cout << ans;
	}else if(flag){
		int l = 0, r = n;
		while(l <= r){
			int mid = (l + r) >> 1;
			long long need = (mid + 1) * mid / 2;
			if(need > m){
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans, min(n, r + 1));
		cout << ans;
	}else{
		int l = 0, r = n;	
		long long cha = a[2] - a[1];
		while(l <= r){
			int mid = (l + r) >> 1;
			long long need = (cha + mid * cha) * mid / 2;
			if(need > m){
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans, min(n, r + 1));
		cout << ans;	
	}
} 
/*
5 5
1 2 4 8 9

5 5
1 2 3 4 5

5 8
-3 -1 2 2 7
*/
//Oct31==Dec25?
