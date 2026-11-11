#include<bits/stdc++.h>
using namespace std;
#define int long long //注意longlong内存

//多测清空
//取消fre注释
//检查格式，检查边界
//注意时空复杂度 

const int N = 2e5 + 5;

int a[N];
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);//注意不混用cin,scanf,getchar
	
	int n, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for(int i = 1; i <= n; i++)
		sum += a[i];
	sum /= 2;
	int l = 1, r = n, sumeach = 0, ans = 0;
	while(sumeach < sum) {
		if(a[l] <= a[r]) {
			int need = min(sum - sumeach, a[l]);
			a[l] -= need;
			a[r] -= need;
			sumeach += need;
			if(c[l] != c[r])
				ans += need;
			if(a[l] == 0)
				l++;
			if(a[r] == 0)
				r--;
		}
		else {
			int need = min(sum - sumeach, a[r]);
			a[l] -= need;
			a[r] -= need;
			sumeach += need;
			if(c[l] != c[r])
				ans += need;
			if(a[l] == 0)
				l++;
			if(a[r] == 0)
				r--;
		} 
	}
	cout << ans;
	
	return 0;
	//Trick or Treat!
	//I_AK_IOI
}

