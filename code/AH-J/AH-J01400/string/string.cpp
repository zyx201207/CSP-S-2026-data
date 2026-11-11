#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n,ans = 0;
    string s = "";
    cin >> n;
    for(ll i = 1; i <= n; i++){
        int x;
        string a;
        cin >> x >> a;
        for(int j = 1; j <= x; j++){
            s += a;
        }
    }
    ll l = 0, r = s.size() - 1;
    while(l <= r){
        if(s[l] != s[r]){
            ans++;
        }
        l++;
        r--;
    }
    cout << ans;
    return 0;
}
