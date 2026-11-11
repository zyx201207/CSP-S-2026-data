#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int ans = 0;
	cin >> n >> m;
	vector<long long> a(n + 1),qzh(n + 1);
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a.begin() + 1,a.begin() + n + 1);
	for(int i = 1;i <= n;i++){
		qzh[i] = a[i] + qzh[i - 1];
		int l = 1,r = i; 
		while(l < r){
			int mid = (l + r) >> 1,k = qzh[i - 1] - qzh[mid - 1];
			if ((i - mid) * a[i] - k < m) r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans,i - l + 1);
	}
	cout << ans;
	return 0;
}
