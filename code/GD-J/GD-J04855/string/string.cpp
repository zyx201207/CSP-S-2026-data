#include <bits/stdc++.h>
using namespace std;

long long n, diff, pos=1, lpos=1, rpos, size;
vector<long long> a;
vector<char> c;
string str;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	rpos = n;
	a.resize(n+1), c.resize(n+1);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		size += a[i];
	}
	
	while (pos <= size/2) {
		if (c[lpos] == c[rpos]) {
			if (a[lpos] > a[rpos]) {
				pos += a[rpos];
				a[lpos]-=a[rpos];
				rpos--;
			} else if (a[lpos] == a[rpos]) {
				pos += a[rpos];
				lpos++, rpos--;
			}
			else {
				pos += a[lpos];
				a[rpos]-=a[lpos];
				lpos++;
			}
		}
		
		else {
			if (a[lpos] > a[rpos]) {
				pos += a[rpos];
				
				diff+=a[rpos]; 
				a[lpos]-=a[rpos];
				rpos--;
			} else if (a[lpos] == a[rpos]) {
				pos += a[rpos];
				diff+=a[rpos];
				
				lpos++, rpos--;
			}
			else {
				pos += a[lpos];
				
				diff+=a[lpos];
				a[rpos]-=a[lpos];
				lpos++;
			}
		}
	}
	cout << diff << '\n';
	return 0;
}
