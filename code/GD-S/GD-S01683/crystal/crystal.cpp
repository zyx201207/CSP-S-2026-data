#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++)cin >> a[i];
	sort(a,a + n);
	long long tmp = 0;
	int ans = 0,x = 0;//[left,i]
	for(int i = 0;i < n;i++){
		tmp += a[i];
		for(;a[i] * (i - x + 1) - tmp > m && x <= i;tmp -= a[x],x++);
		ans = max(ans,i - x + 1);
	}
	cout << ans;
}
