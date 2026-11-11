#include<iostream>
#include<string>
using namespace std;

int main() {

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    string s;
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        string c;
        cin >> c;

        for (int i = 1; i <= a; i++) {
            s += c;
        }
    }

    int i = 0,j = s.length() - 1;
    while (i <= j) {
        if (s[i] != s[j]) {
            ans ++;
            i++;
            j--;
        }else{
            i++;
            j--;
        }
    }
    cout << ans;
    return 0;
}