#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[200001];
char s [200000001];
long long sum = 0, cnt = 0;

int main (){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n ; i++){
        char b;
        cin >> a[i] >> b;
        for (int i = 1; i <= a[i]; i++){
            sum++;
            s[sum] = b;
        }
    }
    int t = sum / 2;
    for (int i = 1; i <= t; i++){
        if (s[i] != s[sum - i + 1]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
