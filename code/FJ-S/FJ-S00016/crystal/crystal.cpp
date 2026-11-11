#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], b[500005], ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		b[i] = a[i]-a[i-1];
	}
	long long l = 1, r = 1, len = 1, num = 0;
	while(r<=n){
		if(m >= (len-1) * b[r]){
			ans = max(ans,len);
			m-=(len-1)*b[r];
			num += b[r];
			len++;
			r++;
		}
		else{
			len--;
			m += num;
			num -= b[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}
