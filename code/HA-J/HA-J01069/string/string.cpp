#include<bits/stdc++.h> 
using namespace std;
int a[200005];
char c[200005];
string s;
string q;

void reserve() {
	for(int i=1, j=s.size(); i<=s.size(); i++, j--) {
		q[j] = s[i];
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, sum = 0, cnt=0;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i] >> c[i];
		for(int j = sum+1; j<=sum+a[i]; j++) {
			s[j] = c[i];
		}
		sum+=a[i];
	}
	reserve();
	for(int i=1; i<=sum; i++) {
		if(q[i] != s[i]) {
			cnt++;
		}
	}
	cout << cnt/2;
	return 0;
}
