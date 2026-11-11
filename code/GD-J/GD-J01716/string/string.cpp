#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	int n, a, k = 0, sum = 0, min;
	string c;
	cin >> n;
	string s[10005];
	for (int i = 1;i<=n;i++){
		cin >> a;
		cin >> c;
		for (int j = k+1;j<=k+a;j++){
			s[j] = c;
			sum++;
		}
		k+=a;
	}
	int h = sum/2;
	min = sum/2;
	for (int i=1;i<=h;i++){
		if (s[i] == s[sum-i+1])
		{
			min--;
		}
	}
	cout << min;
	return 0;
 }
