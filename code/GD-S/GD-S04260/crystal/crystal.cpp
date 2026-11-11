#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool f = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != a[i - 1]){
			f = 0;
		}
	}
	if(f == 1){
		cout << n;
		return 0;
	}
	int bb = 0;
	for(int i = 2; i <= n; i++){
		if(a[i] - a[i - 1] != a[i + 1] - a[i]){
			f = 0;
		}
		bb = a[i] - a[i - 1];
	}
	if(f == 1){
		int mm,cnt = 1;
		while(m > 0){
			m -= mm;
			mm = mm * 2 + bb;
			cnt++;
		}
		return 0;
	}
	sort(a + 1,a + n + 1);
	int ma_ = 0;
	for(int i = n; i >= 1; i--){
		int b = m,cnt = 1;
		for(int j = i - 1; j >= 1; j--){
			int dd = a[i] - a[j];
			if(b < dd){
				break;
			}
			cnt++;
			b -= dd;
		}
		ma_ = max(ma_,cnt);
	}
	cout << ma_;
	return 0;
}
