#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 5e5+5;
long long m, a[N];
long long diff[N];
long long ts[N][N];	//定义状态ts[i][j]代表将i~j变成j的次数

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);

	for(int i = 1; i <= n; i++)	//diff[i] = a[i]-a[i-1]
		diff[i] = a[i] - a[i-1];
	long long mx = 0;
	//将前j个数字变成a[j](ts[j]),需要ts[j-1]+(j-1)*diff[i]
	/*for(long long j = 1; j <= n; j++){
		ts[j] = ts[j-1]+(j-1)*diff[j];
		if(ts[j] > m) break;
		mx = max(mx, j);
	}*/
	//将i~j个数字变成a[j](ts[i][j]),需要ts[i][j-1]+(j-i)*diff[j]
	for(long long l = 1; l <= n; l++){
		if(n-l <= mx) continue;
		for(long long r = l; r <= n; r++){
			if(l==r) ts[l][r] = 0;
			else ts[l][r] = ts[l][r-1]+(r-l)*diff[r];
			if(ts[l][r] > m) break;
			mx = max(mx, r-l);
		}
	}
	cout << mx;
	return 0;
}
