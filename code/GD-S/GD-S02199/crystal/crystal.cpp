#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int ans = -1;
	sort(a+1,a+1+n);
	for (int i = n;i >= 1;i--){
		int use = m;
		int cnt = 1;
		for (int j = i-1;j >= 1;j--){
			if (a[i]-a[j] <= use){
				use -= (a[i]-a[j]);
				cnt++;
			}
			else{
				break;
			}
		}
		if (cnt < ans){
			break;
		}
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
