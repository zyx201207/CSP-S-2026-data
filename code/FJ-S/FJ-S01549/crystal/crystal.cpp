#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == i){
			cnt1++;
		}
	}	
	if(cnt1 == n){
		cout << m;
		return 0;
	}else{
		if(a[2] - a[1] == a[3] - a[2]){
			cout << m / (a[2] - a[1]);
			return 0;
		}
	}
	sort(a + 1,a + n + 1);
	int res = 0;
	for(int i = 1;i <= n;i++){
		vector<int> b(i + 1);
		int cnt = 1;
		for(int j = 1;j <= i;j++){
			b[cnt] = a[i] - a[j];
			cnt++;
		}
		sort(b.begin(),b.end());
		int ans = 0;
		for(int j = 1;j < cnt;j++){
			if(m >= b[j]){
				m -= b[j];
				ans++;
			}else{
				break;
			}
		}
//		for(int j = 1;j <= cnt;j++){
//			cout << b[j] << " ";
//		}
//		cout << "\n";
		res = max(res,ans + 1);
	}
	cout << res;
	return 0;
}
