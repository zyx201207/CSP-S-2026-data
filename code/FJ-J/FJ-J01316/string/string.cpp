#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 2 * 1e5 + 5;
long long a[maxn];
long long sum;
string s;
char c[maxn]; 
int ans = 0;
int check(string x,long long n) {
	int l = 0,r = n - 1;
	while(l <= r) {
		if(x[l] == x[r]) l++,r--;
		else {
			ans++;
			l++,r--;
		}
	} 
	return ans;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
		for(int j = 1;j <= a[i];j++) {
			s += c[i];
		}
	}
	cout << check(s,sum); 
	return 0;
}
/*
3
2 a
2 b
1 c

*/
