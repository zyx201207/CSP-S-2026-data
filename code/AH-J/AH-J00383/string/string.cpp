#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, a, len, ans = 0;
    char c;
    string s;
    cin >> n;
    for (long long i = 1; i <= n; i++){
		cin >> a;
		cin >> c;
		while (a--){
			s += c;
		}
	}
	len = s.size();
	for (long long i = 0; i < len / 2; i++){
		if (s[i] != s[len - i - 1]){
			ans++;
		}
	}
	cout << ans << endl;
	
    return 0;
}
