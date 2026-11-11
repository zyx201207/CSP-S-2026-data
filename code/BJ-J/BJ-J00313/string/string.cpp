#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100007];
char c[100007];
string s;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string .out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cin >> c[i];
        for (int j = 1; j <= a[i]; j++) s += c[i];
    }
    n -= 1;
    int sum = 0;
    for (int i = 0; i <= n; i++){
        if (s[i] != s[n - i]) sum++;
    }
    cout << sum;
    return 0;
}
