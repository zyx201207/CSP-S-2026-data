#include <bits/stdc++.h> 
using namespace std;

string s;
bool check(string x) {
	long long len = x.size();
	for (int i = 0,j = len;i < len && j > 0;) {
		if (i == j || i > j) break;
		if (x[i] == x[j]) {
			i++;
			j--;
		}
		else return 0;
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	while (n) {
		n--;
		long long cnt;
		string a;
		cin >> cnt;
		cin >> a;
		for (int i = 1;i <= cnt;i++) {
			s += a;
		}
	}
	long long lent = s.size();
	long long cnt = 0;
	
	if (check(s)) cout << "0";
	else {
		for (int i = 0,j = lent;i < lent && j > 0;) {
			if (i >= j) break;
			if (s[i] == s[j]) {
				i++;
				j--;
			}
			else {
				cnt++;	
			}
		}
		cout << cnt;
	}
	
	return 0; 
} 
