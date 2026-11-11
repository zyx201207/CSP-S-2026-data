#include<bits/stdc++.h>
using namespace std;
//const ll INF = 4e18;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>> n;
    string s = "";
    for (int i = 0; i < n; ++i) {
        int x;
        char a;
        cin >> x >> a;
        for (int j = 1; j <= x; ++j)
            s += a;
    }
    //cout << n;
    int l = 0, r = s.size()-1;
    int ans = 0;
    while (l < r) {
        if (s[l] != s[r]){
            ans++;
        }
        l++;
        r--;
    }
    cout << ans;
    return 0;
}

