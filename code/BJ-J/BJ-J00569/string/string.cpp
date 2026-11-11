#include <iostream>
#include <string.h>

using namespace std;

string s, s1;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, cnt = 0, num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int q;
        string c;
        cin >> q >> c;
        for (int j = 0; j < q; j++) {
            s += c;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        s1 = s[i];
    }
    int l = s.size();
    for (int i = 1; i <= s.size() / 2; i++) {
        if (s[i] != s1[i]) cnt++;
    }
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
