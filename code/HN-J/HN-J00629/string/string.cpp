#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans,sum;
char c[200005];
signed main(){
	freopen("string.in" ,"r" ,stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int l = 1,r = n;
	while (l < r){
		if (c[l] == c[r]){
			int t = min(a[l],a[r]);
			a[l] -= t;
			a[r] -= t;
			if (a[l] == 0) l++;
			if (a[r] == 0) r--;
		}else{
			ans += min(a[l],a[r]);
			int t = min(a[l],a[r]);
			a[l] -= t;
			a[r] -= t;
			if (a[l] == 0) l++;
			if (a[r] == 0) r--;
		}
	}
	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
//直接计算每一段里有多少个是和对面一样的 
//左边和右边会产生差值 
