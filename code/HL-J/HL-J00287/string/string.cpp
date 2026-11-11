#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int a[200005], ans, n;
char c[200005];
string s;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    s += " ";
    for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++){
			s += c[i];
		}
	}
	int l_c = s.size() / 2;
    for (int i = 1; i <= l_c; i++)
    	if (s[i] != s[s.size() - i])
    		ans++;
	
    cout << ans;	
    return 0;
}
//100+48
