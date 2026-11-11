#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, ans;
string s;

signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        char c;
        cin >> x >> c;
        for(int j = 1; j <= x; j++){
            s += c;
        }
    }
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else{
            ans++;
            //cout << s[l] << " " << s[r];
            l++;
            r--;
        }
    }
    cout << ans;
    return 0;
}

