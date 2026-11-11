#include<bits/stdc++.h>
using namespace std;
long long n, a, ans;
bool f = true;
char c, c1;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf ("%lld", &n);
    for(long long i = 1; i <= n; i++){
        cin >> a >> c;
        if(i > 1) {
            if(c1 != c) f = false;
        }
        ans += a;
        c1 = c;
    }
    cout << (f ? 0 : (long long)ans / 2);
    return 0;
}
//Trick||Treat!
