#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int sum[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	for(int i = 1 ; i <= n ; i ++){
		sum[i] = sum[i - 1] + a[i];
	}
	int maxn = 0;
	for(int i = 1 ; i <= n ; i ++){
		int l = 0,r = i;
		while(l + 1 < r){
			int mid = (l + r) / 2;
			if((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m){
				r = mid;
			}else{
				l = mid;
			}
		}
//		cout << i << " " << r << "\n";
		maxn = max(maxn , i - r + 1);
	}
	cout << maxn;
	return 0;
} 
