#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int a[N],d[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	bool flag = true,ho = true;
	int d; 
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i) flag = false;
		if(i == 1) continue;
		else if(i == 2) d = a[i] - a[i-1];
		else{
			if(a[i] - a[i-1] != d) ho = false;
		}
	}
	if(flag){
		cout << m + 1;
		return 0;
	}
	if(ho){
		cout << 1 + m / d;
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++) d[i] = a[i] - a[i-1],sum[i] = sum[i-1] + d[i];
	int ans = 0,total = 0;
	for (int i = 1;i <= n;i++){
		int num = 1,s = 0;
		for (int l = i-1;l > 0;l--){
			s += sum[i-1] - sum[l-1];
			if(s > m) break;
			num++;
			total++;
		}
		ans = max(ans,num);
	}
	cout << ans;
	return 0;
} 
