//crystal
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
int n,m,a[N];
inline int get(int d){
	vector<int> vec;
	int ret = 0;
	for(int i = 1;i <= n;i++){
		if(d >= a[i]) vec.push_back(d - a[i]);
	}
	sort(vec.begin(),vec.end());
	int cnt = 0;
	for(int i = 0;i < (int)vec.size();i++){
		ret += vec[i];
		if(ret > m) break;
		cnt++;
	}
//	cout << ret << endl;
	return cnt;
}
inline bool check(){
	int d = a[2] - a[1];
	for(int i = 3;i <= n;i++) if(d != (a[i] - a[i - 1])) return false;
	return true;
}
inline int c(int x){
	int sum = 0;
	for(int i = 1;i <= n;i++) if(a[x] > a[i]) sum += (a[x] - a[i]);
	return (sum <= m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int mx = 0;
	for(int i = 1;i <= n;i++) cin >> a[i],mx = max(mx,abs(a[i]));
	sort(a + 1,a + n + 1);
	int ans = -1e18;
	if(n <= 5000){
		for(int i = 1;i <= n;i++) ans = max(ans,get(a[i]));
		cout << ans << endl;
	}
	else if(mx <= 100){
		int ans = -1e18;
		for(int i = -100;i <= 100;i++) ans = max(ans,get(i));
		cout << ans << endl;
	}
	else if(check()){
		int left = 1,right = n,ans = -1;
		while(left <= right){
			int mid = (left + right) / 2;
			if(c(mid)) left = mid + 1,ans = mid;
			else right = mid - 1; 
		} 
		cout << ans << endl;
	}
	return 0;
} // 90pts
