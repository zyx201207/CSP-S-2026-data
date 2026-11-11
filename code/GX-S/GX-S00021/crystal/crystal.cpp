#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500001];
long long b[500001], nn;
bool flag = true;
long long oph(int x){
	long long ans = 0, sum;
	for(long long i = 1; i <= n; i++)
		if(a[i] == a[x])
			ans++;
	sum = ans;
	long long q = 0;
	for(long long i = x; i >= 2; i--){
		q += b[i] * (i - 1);
		if(q > m)
			break;
		ans++;
	}
	q = 0;
	for(long long i = x; i <= n; i++){
		q += b[i] * (n - i + 1);
		if(q > m)
			break;
		sum++;
	}
	return max(sum, ans);
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(long long i = 2; i <= n; i++){
		b[i] = a[i] - a[i - 1];
		if(b[i] != b[i - 1] && i >= 3)
			flag = false;
	}
	if(flag)
		for(long long i = 1; i <= n; i++)
			nn = max(nn, oph(i));
	else{
		long long q = 0;
		for(long long i = 2; i <= n; i++){
			q += b[i] * (i - 1);
			if(q <= m)
				nn++;
			else
				break;
		}
		nn++;
	}
	cout << nn;
	return 0;
}
