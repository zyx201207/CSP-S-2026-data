#include <bits/stdc++.h>
using namespace std;

string s;
long long n,ans=0, a[3000005];
char c[2000005];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (long long i = 1; i <= n; i++){
        scanf("%lld %c", &a[i], &c[i]);
        for (long long j = 1; j <= a[i]; j++){
            s += c[i];
        }
    }
    for (long long i = 0, j = s.size() - 1; i <=j; i++, j--){
        if (s[i] != s[j]) ans++;
    }
    cout << ans;
    return 0;
}
