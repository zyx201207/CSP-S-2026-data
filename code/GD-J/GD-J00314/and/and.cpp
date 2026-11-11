#include <iostream>
#include <vector>
using namespace std;
int n, a[(int)2e5 + 5], m;
vector<int> lst;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int mx = 0;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) mx = max(mx, a[i]);
	for(int i = 1;i <= n;i++) lst.push_back(a[i]);
	int mxbit = 0;
	for(;(1 << mxbit) <= mx;mxbit++);
	mxbit--;
	int ans = 0;
	for(int i = mxbit;i >= 0;i--){
		vector<int> tmp;
		int cnt = 0;
		for(int j : lst){
			if((j >> i) & 1) {
				cnt++, tmp.push_back(j);
			}
		}
		if(cnt >= m){
			ans |= 1 << i;
			lst = tmp;
		}
	}
	cout << ans;
	return 0;
}
		
