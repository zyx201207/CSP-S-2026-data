#include <iostream>
#include <algorithm>
using namespace std;

long long n,m,a[1000005],s[1000005];

bool chk(int mid){
	long long res = 1e18;
	for(int i = mid;i <= n; i++)
		res = min(res,a[i] * mid - (s[i] - s[i-mid]));
	return res <= m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n; i++) s[i] = s[i-1] + a[i];
	int l = 1,r = n;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(chk(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	
	return 0;
}