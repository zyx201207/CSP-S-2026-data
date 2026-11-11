#include <bits/stdc++.h>
using namespace std;
long long a[500005],d[500005],sum[500005];
long long m,n,f;
bool check(int k){
	for(int i = 1; i <= n-k+1; i++){
		long long u = 0;
		for(int j = i; j <= i+k-2; j++){
			u += a[i+k-1]-a[j];
		}
		if(u <= m) return 1;
	}
	return 0;
}
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int s = 0,x = 0;
	for(int i = 1; i < n; i++){
		d[i] = a[i+1] - a[i];
		if(d[i] == d[i-1] && i != 1) x++; 
		if(d[i] == 0) f++;
		if(d[i] < m) s++;
		sum[i] = sum[i-1]+d[i];
	}
	if(s == 0){
		cout << 1 << '\n';
		return 0;
	}
	if(f == n-1){
		cout << n << '\n';
		return 0;
	}
	if(x == n-1){
		long long q = m/(d[n]-d[n-1]);
		int cnt = 0,i = 1;
		while(q > 0){
			q -= i;
			cnt++;
			i++;
		}
	}
	int l = 1,r = n+1;
	while(l < r){
		int mid = (l+r)/2;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	cout << l << '\n'; 
	return 0;
 } 
