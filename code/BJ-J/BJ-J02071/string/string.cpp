#include <bits/stdc++.h>
using namespace std;

bool aba(string s) {
    string s1 = "";
    int x = 0;
    for (int i = s.size()-1; i >= 0; i--) {
        s1[x++] = s[i];
    }
    if (s == s1) return true;
    else return false;
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    long long n, ans=0, a[1000000];
    string c;
    string s="";
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
        for (long long j = 0; j < a[i]; j++) {
            s+=c[i];
        }
    }
    cout << s << endl;
    if (aba(s)) {
        cout << 0;
        return 0;
    }
    long long halfs=s.size()/2, l=0, r=s.size()-1;
    while (l <= halfs && r >= halfs) {
        if (s[l] != s[r]) {
            s[r] = s[l];
            ans++;
        }
        l++;
        r--;
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
