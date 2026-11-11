#include <bits/stdc++.h>

using namespace std;

int n;
long long l;
string s;
long long ans;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    while (n--){
        int a;
        char c;
        cin>>a>>c;
        l += a;
        string str(a, c);
        s += str;
    }
    s = ' '+s;
    int l_ = 1, r = l;
    while (l_ < r){
        if (s[l_] != s[r]){
            ans++;
        }
        l_++;
        r--;
    }
    cout<<ans<<endl;

    return 0;
}
