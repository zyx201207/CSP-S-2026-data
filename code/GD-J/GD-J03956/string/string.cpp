#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	long long n , its1 = -1 , its2 = -1 , len = 0;
	cin >> n;
	vector<char> s1(n + 5);
	vector<char> s2(n + 5);
	vector<long long> m1(n + 5);
	vector<long long> m2(n + 5);
	for(int i = 1; i <= n; i++) {
		long long a;char c;
		cin >> a >> c;
		len += a;
		s1[++its1] = c , m1[its1] = a;
	}
	long long l = len / 2;
	while(l != 0) {
		if(l >= m1[its1]) {
			l -= m1[its1];
			its1-- , its2++;
			s2[its2] = s1[its1 + 1];
			m2[its2] = m1[its1 + 1];
		} else {
			m1[its1] -= l;
			its2++;
			s2[its2] = s1[its1];
			m2[its2] = l;
			l = 0;
		}
	}
	long long sum = 0;
	for(int i = 0 , j = 0;i <= its2;) {
		sum += int(s1[j] != s2[i]) * min(m2[i] , m1[j]);
		if(m2[i] > m1[j])
			m2[i] -= m1[j] , j++;
		else if(m2[i] == m1[j])
			i++ , j++;
		else if(m2[i] < m1[j])
			m1[j] -= m2[i] , i++;
	} 
	cout << sum;
	return 0;
} 
