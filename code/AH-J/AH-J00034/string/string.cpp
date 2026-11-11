#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200005;
string s;
ll n, cnt = 0;
ll a;
char c;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%lld", &n);
    ll idx = 0;
    while(n--){
        scanf("%lld %c", &a, &c);
        ll len = idx + a;
        for(; idx < len; idx++){
            s.push_back(c);
        }
    }
    for(ll i = 0, j = s.size() - 1; i <= j; i++, j--){\
        if(s[i] != s[j]){
            cnt++;
        }
    }
    printf("%lld", cnt);
    return 0;
}
