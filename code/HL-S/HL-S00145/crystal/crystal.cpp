#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool ok1 = 1,ok2 = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i)
			ok1 = 0;
		if(i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
			ok2 = 0;
	}
	if(ok1){
		for(int i = 1;m >= 0;i++)
			m -= i,ans++;
		cout << ans << endl;
		return 0;
	}
	if(ok2){
		ans = m / (a[2] - a[1]) + 1;
		cout << ans << endl;
		return 0;
	}
	cout << n << endl;
	return 0;
} 
