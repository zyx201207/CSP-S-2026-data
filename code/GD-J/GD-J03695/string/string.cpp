#include <bits/stdc++.h>
using namespace std;
long long n , a , ans;
char c;
string s , e;
int main (){
	freopen ("string.in" , "r" , stdin);
	freopen ("string.out" , "w" , stdout); 
	cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> a >> c;
		for (int j = 1 ; j <= a ; j++)  s += c;
	}
	e = s;
	reverse (e.begin () , e.end ());
	for (int i = 0 ; i < s.length () / 2 ; i++)
		if (s[i] != e[i])  ans++;
	cout << ans;
	return 0;
}
