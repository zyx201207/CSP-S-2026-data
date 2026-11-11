#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        ll a;string c;
        cin >> a >> c;
        for (int j = 1;j <= a;j++){
            s += c;
        }
    }
    ll len = s.size();
    for (ll i = 0;i < len/2;i++){
        if (s[i] != s[len-i-1]) cnt++;
    }
    cout << cnt;
    return 0;
}