#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 1e8;
int n;
long long m;
long long a[N];
long long c[N];
long long q[N];
long long Max = LONG_LONG_MIN;
void solve1(){
	for(int i = 2;i <= n;i++){
		c[i] = abs(a[i] - a[i - 1]);
	}
	q[2] = c[2];
	for(int i = 3;i <= n;i++){
		q[i] = c[i] + q[i - 1];
	}
	for(long long i = 1;i <= n;i++){
		if(i == 2 && c[i] <= m) Max = max(Max, i); 
		if(q[i] + c[i] <= m){
			Max = max(Max, i);
		}
		else break;
	}
	cout << Max;
	return ;
}
void solve2(int x){ 
	long long sum = 0;
	for(int i = 1;i <= n;i++){
		sum = sum + (i - 1) * x;
		if(sum > m){
			cout << i - 1;
			break;
		}
	} 
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if(m <= M) solve1();
 	else if(abs(a[n] - a[n - 1]) == abs(a[n - 1] - a[n - 2])) solve2(abs(a[n] - a[n - 1]));
	return 0;
} 
