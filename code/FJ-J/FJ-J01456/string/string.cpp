#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, k = 0, sum = 0, ans1 = 0, ans2 = 0;
	char s[1000005];
	cin>>n;
	for(long long i = 0; i < n; i++) {
		long long x;
		char c;
		cin>>x>>c;
		sum += x;
		for(long long j = 0; j < x; j++) {
			s[k] = c;
			k++;
		}
	}
	int m = sum / 2;
	for(long long i = 0; i < m; i++) {
		if(s[i] == s[sum - i - 1]) continue;
		else ans1++;
	}
	for(long long i = m; i < sum; i++) {
		if(s[i] == s[sum - i - 1]) continue;
		else ans2++;
	}
	cout<<min(ans1, ans2)<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
} 
