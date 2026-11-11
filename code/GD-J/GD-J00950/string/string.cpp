#include<bits/stdc++.h>
using namespace std;
const long long N = 2 * 100000 + 5;
long long n, cnt = 0;
long long a[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(long long i = 0; i < n; i++){
		cin >> a[i] >> c[i];
	}
	long long i = 0, j = n-1;
	while(i < j){
		if(c[i] != c[j]){
			long long x = min(a[i], a[j]);
			cnt += x;
			a[i] -= x; 
			a[j] -= x;
		}
		if(a[i] > 0) j--;
		else if(a[j] > 0) i++;
		else { i++; j--; }
	}
	cout << cnt;
	return 0;
}
