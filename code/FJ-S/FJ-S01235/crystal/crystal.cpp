#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,ans;
long long m,s,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	sort(a,a+n);
	for(int l = 0,r = 0;r < n;r++){
		while(a[r]*(r-l)-s > m)
			s -= a[l++];
		ans = max(ans,r-l+1);
		s += a[r];
	}
	cout << ans;
	return 0;
}
