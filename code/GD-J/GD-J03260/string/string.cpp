#include<iostream>
#include<cstdio>
#include<iostream>
#define int long long 
using namespace std;

int n, a[200005], ans;
char c[200005];
string str;

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {         //O(n*a[i])
        cin >> a[i] >> c[i];
        for(int j = 1; j <= a[i]; j++)
            str += c[i];
    }
    str = '?' + str; 
    for(int i = 1; i <= str.size() / 2; i++) //O(n*a[i] / 2)
        if(str[i] != str[i + str.size() / 2])
            ans++;

    cout << ans;
    return 0;
}

// 56

