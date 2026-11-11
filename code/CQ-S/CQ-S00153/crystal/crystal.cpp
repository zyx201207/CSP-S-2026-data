#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5;
long long n,m,a[N+5],s[N+5];
int ans;
int bs(int x){
	int l=1,r=x,mid;
	while (l <= r){
		mid = (l+r)/2;
		long long num = s[x]-s[mid-1];
		if (a[x]*(x-mid+1)-num <= m) r = mid-1;
		else l = mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) s[i] = s[i-1]+a[i];
	for (int i = 1; i <= n; i++){
		int t = bs(i);
		ans = max(ans,i-t+1);
	}
	cout << ans;
	return 0;
} 
/*
5 5
1 2 4 8 9
*/
